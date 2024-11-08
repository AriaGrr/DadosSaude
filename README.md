# Projeto de Estrutura de Dados
  Aplicativo para gerenciamento de serviços de saúde.

Dentro deste código, há várias opções de operações de acordo com a necessidade do usuário, que são as que seguem:

<h2>Cadastrar</h2>
<p>Dentro desta opção, pode ser registrado um novo paciente(Nome, RG, idade e a data de entrada no sistema), consultar os dados de algum paciente, mostrar todos os pacientes cadastrados, atualizar os dados de um paciente e remover algum paciente da lista de cadastros</p>

<h2>Atendimento</h2>
<p>Dentro desta opção, é feito o enfileiramento dos pacientes para que sejam atendidos por algum médico, então dentro de atendimento,  se tem três opções: </p>
<ul>
  <li>Adicionar um paciente à fila</li>
  <li>Atender um paciente(retirar paciente da fila.)</li>
  <li>Mostra fila de espera inteira(imprimir fila completa). </li>
</ul>

<h2>Pesquisa</h2>
<p>Esta opção serve para a organização dos pacientes cadastrados de acordo com certos aspectos de seus registros. Pode ser organizada os cadastros por: </p>
<ul>
  <li>Ano de entrada</li>
  <li>Mês de entrada</li>
  <li>Dia de entrada</li>
  <li>Idade do paciente</li>
</ul>

<h2>Desfazer</h2>
<p>Esta opção se relaciona com a função de atendimento dos pacientes. Após cada enfileiramento ou desfileiramento de algum paciente, é guardado dentro de um pequeno histórico de todas as operações feitas até o momento. Será mostrada a opção de desfazer a operação mais recente. Caso seja desfileiramento, é adicionado o paciente de volta a fila, caso seja enfileiramento, é feito o contrário, retirando o paciente da fila.</p>

<h2>Carregar</h2>
<p>Apesar do carregamento dos clientes cadastrados ser feito automaticamente no início do programa, é carregado todos os pacientes do arquivo salvo anteriormente para dentro da lista sendo usada atualmente.</p>

<h2>Salvar</h2>
<p>Como o carregar, o salvamento é automático, sendo feito após cada operação. Quando é escolhida esta opção, todos os pacientes são salvos dentro do arquivo binário. </p>

<h1>-> Comandos para execução:</h1> 

```stdin
gcc main.c funcoes.c -o main
```
```stdin
./main
```
