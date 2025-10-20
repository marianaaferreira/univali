import matplotlib
matplotlib.use('TkAgg')  # Evita erro de backend no PyCharm

import pandas as pd
import matplotlib.pyplot as plt

# === Carregamento da base ===
df = pd.read_csv("SC_TS_ALUNO_9EF.csv", sep=";", encoding="utf-8")

# === Padronização de colunas relevantes ===
# Substitua conforme o nome exato das colunas na base
coluna_raca = "TP_COR_RACA"              # código ou nome da raça
coluna_socio = "Q001"                    # exemplo — substitua pelo nível socioeconômico real
coluna_media = "MEDIA_GERAL"             # exemplo — média de desempenho do aluno

# === Filtragem: remover não declarados e sem resposta ===
valores_invalidos = ["", "NA", "NULO", "NÃO DECLARADO", "SEM RESPOSTA", "null", None, "Nan", "nan"]
df = df[~df[coluna_raca].isin(valores_invalidos)]
df = df[~df[coluna_socio].isin(valores_invalidos)]

# === Cálculo do desempenho médio por raça e nível socioeconômico ===
media_por_grupo = (
    df.groupby([coluna_raca, coluna_socio])[coluna_media]
      .mean()
      .reset_index()
)

# === Normalizar médias em percentuais dentro de cada raça ===
media_por_grupo["pct_media"] = (
    media_por_grupo.groupby(coluna_raca)[coluna_media]
    .apply(lambda x: 100 * x / x.max())
    .reset_index(drop=True)
)

# === Plotagem ===
plt.figure(figsize=(10, 6))
for raca, subset in media_por_grupo.groupby(coluna_raca):
    plt.plot(subset[coluna_socio], subset["pct_media"], marker="o", label=raca)

plt.title("Desempenho percentual médio por nível socioeconômico e raça")
plt.xlabel("Nível Socioeconômico")
plt.ylabel("Desempenho médio (%)")
plt.legend(title="Raça")
plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()
plt.show()
