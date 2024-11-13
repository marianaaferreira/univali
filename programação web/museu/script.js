function validaNomeObra() {
    let obra = document.getElementsByName("obra")[0].value;
    if (obra.length < 6) {
        return alert("pelo menos 6 caracteres");
    }
    return true; 
}