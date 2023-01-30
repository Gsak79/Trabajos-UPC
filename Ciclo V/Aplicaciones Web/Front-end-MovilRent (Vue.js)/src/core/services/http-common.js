import axios from "axios";

export default axios.create({

  baseURL: "https://movilrent-socialmed-api.azurewebsites.net/api/v1",

  headers: { "Content-type": "application/json" },
});
