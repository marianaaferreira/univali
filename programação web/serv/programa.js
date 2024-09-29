const express = require('express');
const path = require('path');
const app = express();

// Serve arquivos estáticos da pasta 'public'
app.use(express.static(path.join(__dirname, 'public')));

// Define uma rota para o formulário
app.get('/teste', (req, res) => {
    const texto = req.query.texto;
    res.send(`Olá, mundo! Você enviou: ${texto}`);
});

// Inicia o servidor na porta 3000
app.listen(3000, () => {
    console.log('Servidor rodando em http://localhost:3000');
});