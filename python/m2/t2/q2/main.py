import calculaCustoConsumidor as m1

custoFabrica = float(input("Custo de fabrica do produto:\n"))
custoConsumidor = m1.calculaCustoConsumidor(custoFabrica)
print("Custo ao consumidor:\n", custoConsumidor)