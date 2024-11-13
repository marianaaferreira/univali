function validarForm(){
    const nomeObra = document.getElementById('nomeObra');
    const autor = document.getElementById('autor');
    const ano = document.getElementById('ano');
    const periodo = document.getElementById('periodo');
    const tipo = document.getElementById('tipo');
    const detalhamento = document.getElementById('detalhamento');
    const mensagensErro = document.getElementById('mensagensErro');
    mensagensErro.innerHTML = '';
    let erros = [];

    // Faz o reset das bordas
    for (const campo of [nomeObra, autor, ano, periodo, tipo]) {
        campo.classList.remove('borda-vermelha');
    }

    if(nomeObra.value.length < 6){
        erros.push('Nome da obra deve ter no mínimo 6 caracteres');
        nomeObra.classList.add('borda-vermelha');
    }

    if (autor.value.length < 10) {
        erros.push('Autor deve ter no mínimo 10 caracteres.');
        autor.classList.add('borda-vermelha');
    }

    if (!/^\d{1,4}$/.test(ano.value)) {
        erros.push('Ano deve ser um número válido de até 4 dígitos.');
        ano.classList.add('borda-vermelha');
    }

    if (periodo.value === '') {
        erros.push('O valor de período é obrigatório.');
        periodo.classList.add('borda-vermelha');
    }

    if (tipo.value === '') {
        erros.push('O valor de tipo é obrigatório.');
        tipo.classList.add('borda-vermelha');
    }

    if (erros.length > 0) {
        erros.forEach(erro => {
            const li = document.createElement('li');
            li.textContent = erro;
            mensagensErro.appendChild(li);
        });
    } else {
        adicionarLinha(nomeObra.value, autor.value, ano.value, periodo.value, tipo.value, detalhamento.value);
        document.getElementById('formObras').reset();
    }
}

function adicionarLinha(nomeObra, autor, ano, periodo, tipo, detalhamento) {
    const tabela = document.getElementById('tabelaObras').getElementsByTagName('tbody')[0];
    const linha = tabela.insertRow();
    linha.innerHTML = `
      <td>${nomeObra}</td>
      <td>${autor}</td>
      <td>${ano}</td>
      <td>${periodo}</td>
      <td>${tipo}</td>
      <td><button onclick="excluirLinha(this)">Excluir</button></td>
    `;
  
    const linhaDetalhamento = tabela.insertRow();
    linhaDetalhamento.style.display = 'none';
    linhaDetalhamento.innerHTML = `
      <td colspan="6"><strong>Detalhamento:</strong> ${detalhamento}</td>
    `;
  
    linha.addEventListener('click', () => {
      // Alterna a exibição do detalhamento
      linhaDetalhamento.style.display = linhaDetalhamento.style.display === 'none' ? 'table-row' : 'none';
    });
  }
  
  function excluirLinha(botao) {
    if (confirm('Tem certeza de que deseja excluir esta obra?')) {
      const linha = botao.parentNode.parentNode;
      const linhaDetalhamento = linha.nextElementSibling;
      linha.remove();
      linhaDetalhamento.remove();
    }
}



