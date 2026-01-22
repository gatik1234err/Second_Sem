# Personal Portfolio Website

A modern, responsive portfolio website built with pure HTML, CSS, and JavaScript. Features smooth animations, interactive elements, and a clean design.

## Technologies Used

### HTML5
- Semantic HTML structure
- SVG icons (inline and inline-svg)
- HTML5 video element
- Form validation with HTML5 attributes

### CSS3
- CSS Custom Properties (Variables)
- CSS Grid for layouts
- CSS Flexbox for alignment
- CSS Animations (@keyframes)
- CSS Transitions
- Media Queries for responsiveness
- Backdrop-filter for glassmorphism effect
- Box-shadow for depth and shadows
- Gradients for visual effects
- Transform properties for scaling and rotation

### JavaScript (ES6+)
- DOM manipulation
- Event listeners
- Intersection Observer API for scroll animations
- `requestAnimationFrame` for smooth animations
- Class-based components (TypeWriter)
- Dynamic style injection
- Throttle function for performance

## File Structure

```
htmlmini/
├── index.html          # Main HTML file
├── style.css           # All CSS styles
├── script.js           # All JavaScript functionality
├── README.md           # This file
├── aboutme.mp4         # Self-introduction video
├── school1.jpg         # School image 1
├── school2.jpg         # School image 2
├── school3.jpg         # School image 3
├── school4.jpg         # School image 4
├── githuub.png         # GitHub icon
├── lnkedin.webp        # LinkedIn icon
├── x.svg               # Twitter/X icon
└── discord.png         # Discord icon
```

## Features

### 1. Navigation
- Fixed navbar with smooth scroll
- Responsive hamburger menu for mobile
- Active link highlighting
- Slide-down animation on page load

### 2. Hero Section
- Name and title with staggered fade-in animations
- Call-to-action buttons
- Animated scroll indicator
- Floating background shapes with parallax effect

### 3. Video Section
- HTML5 video player with custom controls
- Auto-play, muted, loop, playsinline attributes
- Responsive 16:9 aspect ratio
- Fallback message for unsupported browsers

### 4. Schools Section
- Grid layout with hover effects
- Clickable cards linking to school websites
- Fallback SVG placeholders for missing images
- Scale and shadow animations on hover

### 5. About Section
- Animated counter statistics
- Gradient background placeholder
- Responsive grid layout

### 6. Skills Section
- Skill cards with progress bars
- Animated progress bar fill on scroll
- Hover effects with elevation
- SVG icons for each skill

### 7. Projects Section
- Project cards with hover tilt effect
- Tag labels for technologies used
- "View Project" links
- Responsive grid layout

### 8. Contact Section
- Contact information with icons
- Social media links with icons
- Responsive contact form
- Floating labels on input focus
- Form submission animation

### 9. Footer
- Simple copyright notice

## Animations & Effects

### Scroll Animations
- Elements fade in and slide up when scrolled into view
- Uses Intersection Observer API for performance
- Counter numbers animate when visible
- Progress bars fill when visible

### Parallax Effect
- Hero background shapes move at different speeds on scroll
- Creates depth and visual interest

### Custom Cursor
- Custom circular cursor with dot
- Scales up when hovering over interactive elements
- Disabled on touch devices

### Magnetic Buttons
- Buttons slightly follow mouse movement
- Creates interactive "magnetic" feel

### Tilt Effect
- Project and skill cards tilt based on mouse position
- 3D perspective transform
- Creates realistic card movement

### Snowfall Effect (Decorative)
- Animated snowflakes in hero section
- Random positions, sizes, and speeds
- Continuous loop animation

## CSS Variables

```css
:root {
    --primary-color: #2d3436;
    --secondary-color: #636e72;
    --accent-color: #6c5ce7;
    --accent-hover: #5b4cdb;
    --text-light: #dfe6e9;
    --text-dark: #2d3436;
    --bg-light: #f8f9fa;
    --bg-dark: #2d3436;
    --card-bg: #ffffff;
    --shadow: 0 10px 40px rgba(0, 0, 0, 0.1);
    --transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
}
```

## Responsive Design

The website is fully responsive with breakpoints at:
- Desktop (>992px)
- Tablet (768px - 992px)
- Mobile (<768px)

## Performance Optimizations

- Throttled scroll event listeners
- CSS animations use `transform` and `opacity` for GPU acceleration
- Dynamic style injection only when needed
- Intersection Observer for efficient scroll detection

## How to Use

1. Open `index.html` in a web browser
2. Scroll through the page to see animations
3. Click navigation links to smooth scroll to sections
4. Hover over cards and buttons for interactive effects
5. Click school cards to visit their websites
6. Use the contact form to send messages
7. Click social icons to visit profiles

## Customization

### Colors
Edit the CSS variables in `style.css` to change the color scheme:
```css
:root {
    --accent-color: #6c5ce7; /* Change this to your preferred color */
}
```

### Content
Edit the sections in `index.html` to personalize:
- Name and title
- School information
- Skills and progress
- Projects
- Contact details
- Social media links

### Video
Replace `aboutme.mp4` with your own video file (same name or update the src).

### Images
Replace the school images with your actual school photos.

## Browser Support

- Chrome (latest)
- Firefox (latest)
- Safari (latest)
- Edge (latest)
- Mobile browsers

## Performance

The website has been optimized for:
- Fast load times
- Smooth animations (60fps)
- Efficient scroll handling
- Minimal reflows and repaints

## Credits

- Design inspired by modern portfolio trends
- Icons from inline SVG
- Gradients and shadows for modern aesthetic

