def validaEmail():
    caractereValido = "! # $ % & ' * + - / = ? ^ _ ` { | } ~"
    email = input("Informe seu email:\n")
    if '@' in email:
        partes = email.split("@")
        dominio = partes[0]
        if dominio == "":
            validado = False
        elif ".com" not in partes[1]:
            validado = False
        else:
            for i in range (len(dominio)):
                if (not dominio[i].isalnum()) and (dominio[i] not in caractereValido):
                    validado = False

    if validado:
        return email
    print("email mal formatado")

def validaStringAlpha():
    if string != "":
        for i in range(len(string)):
            if not string[i].isalpha():
                return False
    else:
        return False
    return True

def validaStringNum():
    if string != "":
        for i in range(len(string)):
            if not string[i].isnum():
                return False
    else:
        return False
    return True

def validaStringAlphaNum():
    if string != "":
        for i in range(len(string)):
            if not string[i].isnum() and not string[i].isalpha():
                return False
    else:
        return False
    return True