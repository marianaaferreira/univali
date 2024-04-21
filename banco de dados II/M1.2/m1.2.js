const { Sequelize, DataTypes } = require("sequelize");
const MYSQL_IP = "localhost";
const MYSQL_LOGIN = "root";
const MYSQL_PASSWORD = "NfiVJxx88f8x";
const DATABASE = "Person";
const sequelize = new Sequelize(DATABASE, MYSQL_LOGIN, MYSQL_PASSWORD, {
  host: MYSQL_IP,
  dialect: "mysql",
  logging: false,
});

const readline = require("readline");
const prompt = require("prompt-sync")();
const fs = require('fs');

const Person = sequelize.define(
  "Person",
  {
    index: {
      type: DataTypes.INTEGER,
    },
    userId: {
      type: DataTypes.STRING,
      //primaryKey: true,
      //autoIncrement: true,
    },
    firstName: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    lastName: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    sex: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    email: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    phone: {
      type: DataTypes.STRING,
    },
    dateOfBirth: {
      type: DataTypes.DATE,
    },
    jobTitle: {
      type: DataTypes.STRING,
    },
  },
  {
    tableName: "person",
    timestamps: false,
  }
);

async function importCSVData(filename) {
  try {
    await Person.sync({ alter: true });

    const file = fs.createReadStream(filename);
    const rl = readline.createInterface({
      input: file,
      crlfDelay: Infinity,
    });

    let firstLine = true;

    for await (const line of rl) {
      try {
        if (firstLine) {
          firstLine = false;
          continue;
        }

        const field = line.split(",");
        const fixedField = field.map((valor) => valor.replace(/"/g, ""));

        const [
          index,
          userId,
          firstName,
          lastName,
          sex,
          email,
          phone,
          dateOfBirth,
          jobTitle,
        ] = fixedField;

        await Person.create({
          index,
          userId,
          firstName,
          lastName,
          sex,
          email,
          phone,
          dateOfBirth,
          jobTitle,
        });

        console.log("Registro inserido com sucesso:", field);
      } catch (error) {
        console.error("Erro ao inserir registro:", error);
      }
    }

    console.log("Dados importados com sucesso.");
  } catch (error) {
    console.error("Erro ao importar dados:", error);
  }
}

async function displayAllData() {
  try {
    const allData = await Person.findAll();
    console.log("Dados importados:");
    allData.forEach((person) => {
      console.log(person.toJSON());
    });
  } catch (error) {
    console.error("Erro ao exibir dados:", error);
  }
}

async function askForName() {
  const name = prompt("Digite um nome: ");
  await filterByName(name);
}

async function filterByName(name) {
  try {
    const filteredData = await Person.findAll({
      where: {
        firstName: {
          [Sequelize.Op.like]: %${name}%,
        },
      },
    });
    console.log(Registros com o nome contendo "${name}":);
    filteredData.forEach((person) => {
      console.log(person.toJSON());
    });
  } catch (error) {
    console.error("Erro ao filtrar dados por nome:", error);
  }
}

async function mainMenu() {
  while (true) {
    console.log("Selecione uma opção:");
    console.log("1. Exibir todos os dados importados");
    console.log("2. Filtrar dados por nome");
    console.log("3. Importar dados CSV");
    console.log("0. Sair");

    const choice = parseInt(prompt("Digite a opção desejada: "));

    switch (choice) {
      case 1:
        await displayAllData();
        break;
      case 2:
        await askForName();
        break;
      case 3: 
        await importCSVData("people-100000.csv");
        break;
      case 0:
        console.log("Saindo...");
        process.exit(0);
      default:
        console.log("Opção inválida. Por favor, escolha novamente.");
        break;
    }
  }
}

sequelize
  .sync()
  .then(() => {
    console.log("Schema do banco de dados sincronizado com sucesso.");
  })
  .then(async () => {
    await mainMenu();
  })
  .catch((error) => {
    console.error("Erro ao sincronizar schema do banco de dados:", error);
  });
