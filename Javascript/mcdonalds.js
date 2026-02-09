const menuData = [
{
"id": 1,
"name": "Big Mac",
"price": 5.99,
"category": "Burgers",
"image": "https://s7d1.scene7.com/is/image/mcdonalds/Header_BigMac_832x472:1-3-product-tile-desktop?wid=765&hei=472&dpr=off&quot;,
"desc": "Mouthwatering perfection. Two 100% beef patties."
},
{
"id": 2,
"name": "Quarter Pounder",
"price": 6.39,
"category": "Burgers",
"image": "https://upload.wikimedia.org/wikipedia/commons/c/ce/McDonald%27s_Quarter_Pounder_with_Cheese%2C_United_States.jpg&quot;,
"desc": "100% fresh beef, hot, deliciously juicy."
},
{
"id": 3,
"name": "World Famous Fries",
"price": 2.99,
"category": "Sides",
"image": "https://5.imimg.com/data5/YO/GN/MY-33353830/mcdonald-french-fries-28small-2f-medium-2f-large-29.png&quot;,
"desc": "Golden on the outside, soft and fluffy on the inside."
},
{
"id": 4,
"name": "Chicken McNuggets",
"price": 4.49,
"category": "Chicken",
"image": "https://food.fnr.sndimg.com/content/dam/images/food/fullset/2013/9/12/1/FN_Picky-Eaters-Chicken-Nuggets_s4x3.jpg.rend.hgtvcom.1280.1280.suffix/1383770571120.webp&quot;,
"desc": "Tender, juicy chicken breast meat in a tempura coating."
},
{
"id": 5,
"name": "Coca-Cola",
"price": 1.99,
"category": "Drinks",
"image": "https://www.rd.com/wp-content/uploads/2020/10/mcdonalds-coke-collage.jpg&quot;,
"desc": "A cold, refreshing Coca-Cola® soda."
},
{
"id": 6,
"name": "Oreo McFlurry",
"price": 3.29,
"category": "Desserts",
"image": "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQVW3_lrqCe3OGyemNKVZmFXV--LZdKkCUGNQ&s&quot;,
"desc": "Creamy vanilla soft serve with crunchy OREO® pieces."
}
]

const menuContainer = document.getElementById("menu-area");
function displayMenu() {
menuData.forEach(item => {
const itemDiv = document.createElement("div");
itemDiv.classList.add("food-card");
itemDiv.innerHTML = `
<img src="${item.image}" alt="${item.name}">
<h3>${item.name}</h3>
<p>${item.desc}</p>
<span>$${item.price.toFixed(2)}</span>
`;
menuContainer.appendChild(itemDiv);
});
}
displayMenu();
const menuArea = document.getElementById('menu-area');
async function loaderMenu(){
menuArea.innerHTML = `<div class="loader"></div>`;
await new Promise(resolve => setTimeout(resolve, 2000)); // Simulate loading time
menuArea.innerHTML = ''; // Clear loader
// displayMenu(); // Display menu items
}