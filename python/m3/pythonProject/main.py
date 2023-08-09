from pymongo import MongoClient

connection = "mongodb+srv://marianaafeerreira:GE0eDr6wolM8ML12@cluster0.bumogkc.mongodb.net/?retryWrites=true&w=majority"

client = MongoClient(connection)

database = client['db']
collection = database['disciplinas']


def listar_documentos():
  for document in collection.find():
    print(document)

def filtrar_documentos(termo_busca):
  achou = False
  query = {'disciplina': {'$regex': termo_busca}}
  for document in collection.find(query):
    print(document)
    achou = True
  if not achou:
    print("Documento não encontrado")

def inserir_documentos(disciplina, professor):
  documento = {'disciplina': disciplina, 'professor': professor}
  collection.insert_one(documento)
  print("Documento inserido")

def excluir_documentos(atributo, valor):
  achou = False
  query = {atributo: {'$regex': valor}}
  for document in collection.find(query):
    collection.delete_many(query)
    print("Documento excluído")
    achou = True
  if not achou:
    print("Documento não encontrado. Impossível excluir")

opcao = ''
while opcao!='5':
  print('Menu:')
  print('1) Listar todos os documentos')
  print('2) Filtrar documentos')
  print('3) Inserir novos documentos')
  print('4) Excluir documentos')
  print('5) Sair')
  opcao = input('Escolha uma opção: ')

  if opcao == '1':
    listar_documentos()
  elif opcao == '2':
    termo_busca = input('Digite o nome da disciplina que deseja pesquisar:\n')
    filtrar_documentos(termo_busca)
  elif opcao == '3':
    disciplina = input("Disciplina:\n")
    professor = input("Professor:\n")
    inserir_documentos(disciplina, professor)
  elif opcao == '4':
    atributo = input('Digite o atributo pelo qual quer pesquisar:\n')
    valor = input('Digite o valor referente ao atributo escolhido que deseja excluir:\n')
    excluir_documentos(atributo, valor)
  else:
    if(opcao<'1' or opcao>'5'):
      print("Opcão inválida")
