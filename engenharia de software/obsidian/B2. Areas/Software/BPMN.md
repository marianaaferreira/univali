Business
Process
Model and
Notation

- tem conformidade com todo o ambiente de execução (nisso se difere da [[UML]])
- pontos positivos:
	- fácil compreensão
	- padrão entre design e implementação
	- padrão entre modelo e notação

- BPMN contempla 3 diagramas 
- é orientada a processos 
- usada principalmente por profissionais de negócios 

Dicas de como estudar BPMN
- documento de especificação da OMG
- reference cards
- exemplos
- caso não tenha motivo pra modelar, INVENTE um
- muito importante praticar
- os elementos tem frequência de uso distintas

Aplicação
- modelos básicos:
	- processos (orquestração = trocas entre sistemas, controle central)
	- coreografias (apresenta as iterações dos protocolos)
	- colaborações 

Elementos básicos 
- objetos de fluxo 
	- evento
		- algo que acontece na execução do processo
		- geralmente tem uma causa e um impacto
		- bastante utilizado
		- círculos com centros abertos
		- dependendo da posição que ele está no projeto ele pode ter os estados possíveis: start, intermediate e end
	- atividade
		- retângulo vazado
		- trabalho que a empresa realiza
	- gateways
		- losango vazado
- dados
	- fornecem informações sobre o que as atividades necessitam
	- desenho de um documento
- objetos conectores
	- fluxos de sequencia
	- fluxos de mensagem (sua execução depende de uma mensagem)
	- associações (elementos externos)
	- associações de dados
	- variações
- raias
	- duas formas de representar: pools e lanes
	![[Pasted image 20240515210708.png]]
- artefatos
	-  fornecer informações adicionais ao processo
	 - dois artefatos padrão, pode ser criado mais variações
	 - grupo:
		 - usado pra criar contexto dentro do diagrama de negócio
	- anotações de texto

Exemplos:
- [[E1. Tratamento de tickets]]
- [[E2. Gestão de Incidentes]]
- [[E3. Envio de encomendas]]
- [[E4. Pedido de Pizza]]
- [[E5. Passagens corporativas]]
- [[E6. Consulta médica]]


                                                       11 de maio de 2024
                                                       15 de maio de 2024
                                                       