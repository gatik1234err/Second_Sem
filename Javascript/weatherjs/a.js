const API_KEY = "49e1a89335234a6ca9750457261002";
const BASE_URL = "http://api.weatherapi.com/v1/current.json";

async function getWeather() {
  const cityInput = document.getElementById("cityInput").value.trim();
  const resultDiv = document.getElementById("weatherResult");

  if (!cityInput) {
    resultDiv.innerHTML = "<p>Enter a city first, you globalist fool!</p>";
    return;
  }

  resultDiv.innerHTML = "<p>Loading... Build that wall while waiting.</p>";

  try {
    const query = `?key=${API_KEY}&q=${encodeURIComponent(cityInput)}`;
    const response = await fetch(`${BASE_URL}${query}`);
    const data = await response.json();

    if (data.error) {
      resultDiv.innerHTML = `<p>Error ${data.error.code}: ${data.error.message}—fix your shit.</p>`;
    } else {
      const current = data.current;
      const location = data.location;
      resultDiv.innerHTML = `
        <h2>${location.name}, ${location.country}</h2>
        <p>${current.condition.text} | ${current.temp_c}°C (Feels: ${current.feelslike_c}°C)</p>
        <p>Humidity: ${current.humidity}% | Wind: ${current.wind_kph} kph (${current.wind_dir}) | Precip: ${current.precip_mm}mm</p>
        <img src="${current.condition.icon}" alt="Weather icon">
        <p>UV: ${current.uv} | Visibility: ${current.vis_km}km</p>
      `;
    }
  } catch (error) {
    resultDiv.innerHTML = "<p>Network error—blame</p>";
    console.error(error);
  }
}
