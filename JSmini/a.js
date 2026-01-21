document.addEventListener("DOMContentLoaded", function () {
  const demo = document.getElementById("demo");
  const hideBtn = document.getElementById("hideBtn");
  const showBtn = document.getElementById("showBtn");

  hideBtn.addEventListener("click", function () {
    demo.style.display = "none";
  });

  showBtn.addEventListener("click", function () {
    demo.style.display = "block";
  });
});
