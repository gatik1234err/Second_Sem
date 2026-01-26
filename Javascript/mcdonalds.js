function getBill() {
  var msg = "";

  if (document.getElementById("meal1").checked) {
    msg = "Burger Meal Selected <br> Total: ₹100";
  } else if (document.getElementById("meal2").checked) {
    msg = "Fries Meal Selected <br> Total: ₹50";
  } else if (document.getElementById("meal3").checked) {
    msg = "Ice Cream Selected <br> Total: ₹30";
  } else {
    msg = "Please select a meal first.";
  }

  document.getElementById("result").innerHTML = msg;
}
