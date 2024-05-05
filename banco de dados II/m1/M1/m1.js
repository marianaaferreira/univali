const { Sequelize, DataTypes } = require("sequelize");
const MYSQL_IP = "localhost";
const MYSQL_LOGIN = "root";
const MYSQL_PASSWORD = "root";
const DATABASE = "sakila";
const sequelize = new Sequelize(DATABASE, MYSQL_LOGIN, MYSQL_PASSWORD, {
  host: MYSQL_IP,
  dialect: "mysql",
  logging: false,
});

const prompt = require("prompt-sync")();

const Customer = sequelize.define(
  "Customer",
  {
    customer_id: {
      type: DataTypes.INTEGER,
      autoIncrement: true,
      primaryKey: true,
    },
    store_id: { type: DataTypes.INTEGER },
    first_name: { type: DataTypes.STRING, allowNull: false },
    last_name: { type: DataTypes.STRING, allowNull: false },
    email: { type: DataTypes.STRING },
    address_id: { type: DataTypes.INTEGER },
  },
  { tableName: "customer", timestamps: false }
);
const Address = sequelize.define(
  "Address",
  {
    address_id: {
      type: DataTypes.INTEGER,
      autoIncrement: true,
      primaryKey: true,
    },
    address: { type: DataTypes.STRING },
    postal_code: { type: DataTypes.STRING, allowNull: false },
    district: { type: DataTypes.STRING },
    city_id: { type: DataTypes.INTEGER },
    phone: { type: DataTypes.STRING },
    location: { type: DataTypes.GEOMETRY },
  },
  { tableName: "address", timestamps: false }
);

const City = sequelize.define(
  "City",
  {
    city_id: {
      type: DataTypes.INTEGER,
      autoIncrement: true,
      primaryKey: true,
    },
    city: { type: DataTypes.STRING },
    country_id: { type: DataTypes.INTEGER }
  },
  { tableName: "city", timestamps: false }
);

Customer.belongsTo(Address, { foreignKey: "address_id" });
City.hasMany(Address, { foreignKey: "city_id" });

async function listCustomers() {
  let customers = await Customer.findAll({
    include: Address,
  });

  customers.forEach((customer) => {
    console.log(
      Customer: ${customer.first_name} ${customer.last_name} | Address: ${customer.dataValues.Address.dataValues.address}
    );
  });
}

async function listAddresses() {
  let addresses = await Address.findAll();

  addresses.forEach(async (address) => {
    let city = await City.findByPk(address.city_id);
    console.log(Address: ${address.address} - ${city.dataValues.city});
  });
}

async function listIdCities() {
  let cities = await City.findAll();

  cities.forEach(async (city) => {
    console.log(City ID: ${city.city_id});
  });
}

async function addAddress() {
  try {
    const address2 = prompt("Inform the customer's address: ");
    const postalCode = prompt("Inform the customer's postal code: ");
    const district2 = prompt("Inform the customer's district: ");
    const cityId = prompt("Inform the customer's city: ");
    const phoneNumber = prompt("Inform the customer's phone number: ");
    const point = { type: "Point", coordinates: [-76.984722, 39.807222] };

    let address = {
      address: address2,
      postal_code: postalCode,
      district: district2,
      city_id: cityId,
      phone: phoneNumber,
      location: point,
    };

    let returnObject = await Address.create(address);
    console.log(returnObject.address_id);
  } catch (error) {
    console.error("Error log", error);
  }
}

async function addCity() {
  try {
    const city2 = prompt("Inform the name of the city: ");
    const countryId = prompt("Inform the country ID of the city: ");

    let city = {
      city: city2,
      country_id: countryId,
    };

    let returnObject = await City.create(city);
    console.log(returnObject.city_id);
  } catch (error) {
    console.error("Error log", error);
  }
}

async function mainMenu() {
  while (true) {
    console.log("1. List clients");
    console.log("2. List addresses");
    console.log("3. List city IDs");
    console.log("4. Add client");
    console.log("5. Add address");
    console.log("6. Add city");
    console.log("7. Exit");

    const choice = parseInt(prompt("Choose an option: "));

    switch (choice) {
      case 1:
        await listCustomers();
        break;
      case 2:
        await listAddresses();
        break;
      case 3:
        await listIdCities();
        break;
      case 4:
        await addCustomer();
        break;
      case 5:
        await addAddress();
        break;
      case 6:
        await addCity();
        break;
      case 7:
        console.log("Exiting the program.");
        process.exit(0);
      default:
        console.log("Invalid option. Please choose again.");
        break;
    }
  }
}

mainMenu();








/*const Customer = sequelize.define( 'Customer',{
    customer_id: {type: DataTypes.INTEGER, autoIncrement: true, primaryKey: true },
    store_id: {type: DataTypes.INTEGER, allowNull: false},
    first_name: {type: DataTypes.STRING, allowNull: false},
    last_name: {type: DataTypes.STRING, allowNull: false},
    email: {type: DataTypes.STRING},
    address_id: {type: DataTypes.STRING, allowNull: false},
    active: {type: DataTypes.INTEGER, allowNull: false},
    create_date: {type: DataTypes.DATE, allowNull: false},
    last_update: {type: DataTypes.DATE}
}, {tableName: 'customer',timestamps: false});*/



