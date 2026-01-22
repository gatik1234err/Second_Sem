// Portfolio Website JavaScript

document.addEventListener("DOMContentLoaded", () => {
  // Initialize all animations and interactions
  initLoader();
  initCustomCursor();
  initSmoothScroll();
  initScrollAnimations();
  initCounterAnimations();
  initSkillProgress();
  initMobileMenu();
  initNavbarScroll();
  initFormAnimation();
  initParallaxEffect();
});

// Loader Animation
function initLoader() {
  const loader = document.querySelector(".loader");
  if (!loader) return;

  window.addEventListener("load", () => {
    setTimeout(() => {
      loader.classList.add("hidden");
      document.body.style.overflow = "auto";
    }, 1500);
  });
}

// Custom Cursor
function initCustomCursor() {
  const cursor = document.querySelector(".cursor");
  const cursorDot = document.querySelector(".cursor-dot");

  if (!cursor || !cursorDot) return;

  // Check if device supports hover (not mobile)
  if (window.matchMedia("(hover: hover)").matches) {
    document.addEventListener("mousemove", (e) => {
      cursor.style.left = e.clientX + "px";
      cursor.style.top = e.clientY + "px";
      cursorDot.style.left = e.clientX + "px";
      cursorDot.style.top = e.clientY + "px";
    });

    // Add hover effect on interactive elements
    const interactiveElements = document.querySelectorAll(
      "a, button, .project-card, .skill-card",
    );

    interactiveElements.forEach((el) => {
      el.addEventListener("mouseenter", () => {
        cursor.style.transform = "scale(2)";
        cursorDot.style.transform = "scale(2)";
      });

      el.addEventListener("mouseleave", () => {
        cursor.style.transform = "scale(1)";
        cursorDot.style.transform = "scale(1)";
      });
    });
  }
}

// Smooth Scroll for Navigation Links
function initSmoothScroll() {
  document.querySelectorAll('a[href^="#"]').forEach((anchor) => {
    anchor.addEventListener("click", function (e) {
      e.preventDefault();
      const target = document.querySelector(this.getAttribute("href"));
      if (target) {
        const headerOffset = 80;
        const elementPosition = target.getBoundingClientRect().top;
        const offsetPosition =
          elementPosition + window.pageYOffset - headerOffset;

        window.scrollTo({
          top: offsetPosition,
          behavior: "smooth",
        });
      }
    });
  });
}

// Scroll Animations (Fade In on Scroll)
function initScrollAnimations() {
  const animatedElements = document.querySelectorAll(".animate-on-scroll");

  const observerOptions = {
    root: null,
    rootMargin: "0px",
    threshold: 0.1,
  };

  const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        entry.target.classList.add("visible");

        // Trigger counter animation for stat numbers
        const statNumbers = entry.target.querySelectorAll(".stat-number");
        statNumbers.forEach((stat) => {
          animateCounter(stat);
        });

        // Trigger skill progress bars
        const progressBars = entry.target.querySelectorAll(".progress-bar");
        progressBars.forEach((bar) => {
          const width = bar.getAttribute("data-width");
          setTimeout(() => {
            bar.style.width = width + "%";
          }, 200);
        });
      }
    });
  }, observerOptions);

  animatedElements.forEach((el) => observer.observe(el));
}

// Counter Animation
function animateCounter(element) {
  const target = parseInt(element.getAttribute("data-target"));
  const duration = 2000;
  const step = target / (duration / 16);
  let current = 0;

  const timer = setInterval(() => {
    current += step;
    if (current >= target) {
      element.textContent = target + "+";
      clearInterval(timer);
    } else {
      element.textContent = Math.floor(current);
    }
  }, 16);
}

// Skill Progress Bar Animation
function initSkillProgress() {
  const progressBars = document.querySelectorAll(".progress-bar");

  const observerOptions = {
    root: null,
    rootMargin: "0px",
    threshold: 0.5,
  };

  const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        const width = entry.target.getAttribute("data-width");
        setTimeout(() => {
          entry.target.style.width = width + "%";
        }, 300);
        observer.unobserve(entry.target);
      }
    });
  }, observerOptions);

  progressBars.forEach((bar) => observer.observe(bar));
}

// Mobile Menu Toggle
function initMobileMenu() {
  const hamburger = document.querySelector(".hamburger");
  const navLinks = document.querySelector(".nav-links");

  if (!hamburger || !navLinks) return;

  hamburger.addEventListener("click", () => {
    hamburger.classList.toggle("active");
    navLinks.classList.toggle("active");
  });

  // Close menu when clicking on a link
  document.querySelectorAll(".nav-links a").forEach((link) => {
    link.addEventListener("click", () => {
      hamburger.classList.remove("active");
      navLinks.classList.remove("active");
    });
  });

  // Add mobile styles dynamically
  if (!document.getElementById("mobile-styles")) {
    const style = document.createElement("style");
    style.id = "mobile-styles";
    style.textContent = `
            @media (max-width: 768px) {
                .nav-links {
                    position: fixed;
                    top: 70px;
                    left: 0;
                    width: 100%;
                    background: white;
                    flex-direction: column;
                    align-items: center;
                    padding: 30px 0;
                    gap: 25px;
                    transform: translateY(-150%);
                    transition: transform 0.3s ease;
                    box-shadow: 0 10px 30px rgba(0,0,0,0.1);
                }
                
                .nav-links.active {
                    transform: translateY(0);
                }
                
                .hamburger.active span:nth-child(1) {
                    transform: rotate(45deg) translate(5px, 5px);
                }
                
                .hamburger.active span:nth-child(2) {
                    opacity: 0;
                }
                
                .hamburger.active span:nth-child(3) {
                    transform: rotate(-45deg) translate(7px, -6px);
                }
            }
        `;
    document.head.appendChild(style);
  }
}

// Navbar Scroll Effect
function initNavbarScroll() {
  const navbar = document.querySelector(".navbar");
  let lastScroll = 0;

  window.addEventListener("scroll", () => {
    const currentScroll = window.pageYOffset;

    if (currentScroll > 100) {
      navbar.style.boxShadow = "0 5px 20px rgba(0,0,0,0.1)";
    } else {
      navbar.style.boxShadow = "none";
    }

    lastScroll = currentScroll;
  });
}

// Form Input Animation
function initFormAnimation() {
  const formGroups = document.querySelectorAll(".form-group");

  formGroups.forEach((group) => {
    const input = group.querySelector("input, textarea");
    if (!input) return;

    input.addEventListener("focus", () => {
      group.classList.add("focused");
    });

    input.addEventListener("blur", () => {
      if (!input.value) {
        group.classList.remove("focused");
      }
    });
  });

  // Form Submission
  const form = document.querySelector(".contact-form");
  if (form) {
    form.addEventListener("submit", (e) => {
      e.preventDefault();

      const submitBtn = form.querySelector(".btn-submit");
      const originalText = submitBtn.innerHTML;

      // Show loading state
      submitBtn.innerHTML = "<span>Sending...</span>";
      submitBtn.disabled = true;

      // Simulate form submission
      setTimeout(() => {
        submitBtn.innerHTML = "<span>Message Sent!</span> ✓";
        submitBtn.style.background = "#00b894";

        // Reset form
        setTimeout(() => {
          form.reset();
          submitBtn.innerHTML = originalText;
          submitBtn.disabled = false;
          submitBtn.style.background = "";
        }, 2000);
      }, 1500);
    });
  }
}

// Parallax Effect for Hero Shapes
function initParallaxEffect() {
  const shapes = document.querySelectorAll(".shape");

  window.addEventListener("scroll", () => {
    const scrolled = window.pageYOffset;

    shapes.forEach((shape, index) => {
      const speed = 0.05 * (index + 1);
      shape.style.transform = `translateY(${scrolled * speed}px)`;
    });
  });
}

// Text Typing Animation (Optional enhancement)
class TypeWriter {
  constructor(element, text, speed = 100) {
    this.element = element;
    this.text = text;
    this.speed = speed;
    this.index = 0;
  }

  type() {
    if (this.index < this.text.length) {
      this.element.textContent += this.text.charAt(this.index);
      this.index++;
      setTimeout(() => this.type(), this.speed);
    }
  }

  start() {
    this.element.textContent = "";
    this.type();
  }
}

// Initialize typing animation for hero title
function initTypeWriter() {
  const subtitle = document.querySelector(".hero-subtitle");
  if (!subtitle) return;

  const text = subtitle.textContent;
  subtitle.textContent = "";

  const writer = new TypeWriter(subtitle, text, 80);
  writer.start();
}

// Magnetic Button Effect
function initMagneticButtons() {
  const buttons = document.querySelectorAll(".btn");

  buttons.forEach((button) => {
    button.addEventListener("mousemove", (e) => {
      const rect = button.getBoundingClientRect();
      const x = e.clientX - rect.left - rect.width / 2;
      const y = e.clientY - rect.top - rect.height / 2;

      button.style.transform = `translate(${x * 0.2}px, ${y * 0.2}px)`;
    });

    button.addEventListener("mouseleave", () => {
      button.style.transform = "translate(0, 0)";
    });
  });
}

// Image Tilt Effect
function initTiltEffect() {
  const cards = document.querySelectorAll(".project-card, .skill-card");

  cards.forEach((card) => {
    card.addEventListener("mousemove", (e) => {
      const rect = card.getBoundingClientRect();
      const x = e.clientX - rect.left;
      const y = e.clientY - rect.top;

      const centerX = rect.width / 2;
      const centerY = rect.height / 2;

      const rotateX = (y - centerY) / 20;
      const rotateY = (centerX - x) / 20;

      card.style.transform = `perspective(1000px) rotateX(${rotateX}deg) rotateY(${rotateY}deg) translateZ(10px)`;
    });

    card.addEventListener("mouseleave", () => {
      card.style.transform =
        "perspective(1000px) rotateX(0) rotateY(0) translateZ(0)";
    });
  });
}

// Initialize additional effects
document.addEventListener("DOMContentLoaded", () => {
  setTimeout(() => {
    initTypeWriter();
    initMagneticButtons();
    initTiltEffect();
  }, 2000);
});

// GSAP-like ScrollTrigger simulation (Lightweight alternative)
// This creates smooth reveal animations without external libraries
function createScrollReveal() {
  const revealElements = document.querySelectorAll(".reveal");

  const observer = new IntersectionObserver(
    (entries) => {
      entries.forEach((entry) => {
        if (entry.isIntersecting) {
          entry.target.classList.add("revealed");
        }
      });
    },
    { threshold: 0.1 },
  );

  revealElements.forEach((el) => observer.observe(el));
}

// Add dynamic styles for reveal animation
const revealStyles = document.createElement("style");
revealStyles.textContent = `
    .reveal {
        opacity: 0;
        transform: translateY(30px);
        transition: all 0.8s cubic-bezier(0.4, 0, 0.2, 1);
    }
    
    .reveal.revealed {
        opacity: 1;
        transform: translateY(0);
    }
`;
document.head.appendChild(revealStyles);

// Snowfall Effect (Seasonal/Decorative)
function initSnowfall() {
  const hero = document.querySelector(".hero");
  if (!hero) return;

  const snowContainer = document.createElement("div");
  snowContainer.className = "snowfall";
  snowContainer.style.cssText = `
        position: absolute;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        pointer-events: none;
        overflow: hidden;
        z-index: 1;
    `;
  hero.appendChild(snowContainer);

  // Create snowflakes
  for (let i = 0; i < 50; i++) {
    const snowflake = document.createElement("div");
    snowflake.className = "snowflake";
    snowflake.style.cssText = `
            position: absolute;
            top: -10px;
            width: ${Math.random() * 5 + 2}px;
            height: ${Math.random() * 5 + 2}px;
            background: white;
            border-radius: 50%;
            left: ${Math.random() * 100}%;
            opacity: ${Math.random() * 0.5 + 0.3};
            animation: fall ${Math.random() * 3 + 2}s linear infinite;
            animation-delay: ${Math.random() * 5}s;
        `;
    snowContainer.appendChild(snowflake);
  }

  // Add animation keyframes
  const keyframes = document.createElement("style");
  keyframes.textContent = `
        @keyframes fall {
            0% {
                transform: translateY(-10px) rotate(0deg);
            }
            100% {
                transform: translateY(100vh) rotate(360deg);
            }
        }
    `;
  document.head.appendChild(keyframes);
}

// Uncomment to enable snowfall effect:
initSnowfall();

// Performance optimization: Throttle scroll events
function throttle(func, limit) {
  let inThrottle;
  return function (...args) {
    if (!inThrottle) {
      func.apply(this, args);
      inThrottle = true;
      setTimeout(() => (inThrottle = false), limit);
    }
  };
}

// Apply throttling to scroll-intensive operations
window.addEventListener(
  "scroll",
  throttle(() => {
    // Scroll-based operations here
  }, 10),
);

console.log("Portfolio website loaded successfully!");
