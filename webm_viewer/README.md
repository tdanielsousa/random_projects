# WebM Viewer

A single-file HTML page that plays up to 9 random WebM clips at once in a grid, with an optional automatic 10-second rotation. Everything runs locally in the browser, so your files are never uploaded anywhere.

> Note: Clips are picked at random from your selection, so the same file can appear more than once in the grid.
---

##  How It Works

The page is plain HTML, CSS and vanilla JavaScript, with no dependencies or build step.

### Technical Specifications
* **Grid Layout:** A CSS grid of 9 `<video>` elements (3 columns on desktop, 2 columns under 600px wide).
* **Playback:** Every video is muted, looping and set to autoplay (`playsInline` is enabled for mobile).
* **Local Files:** Files are loaded through `URL.createObjectURL`, and the previous object URLs are revoked on each shuffle to avoid memory leaks.
* **Randomization:** Each of the 9 slots picks a random file from the selected list.

---

##  Controls

* **Choose files:** Select one or more `.webm` files from your computer.
* **Randomize Clips:** Assigns a new random clip to each of the 9 slots.
* **10 second rotation:** Toggles an automatic re-randomize every 10 seconds (`ON` / `OFF`).

If no files are selected, an alert asks you to choose some first.

---

## Installation & Run Steps

### 1. Download the Page
Save the code as an `.html` file, for example `webm_viewer.html`.

### 2. Open It
Double-click the file to open it in any modern browser, no server needed.

### 3. Load and Play
Click **Choose files**, select your WebM files, then hit **Randomize Clips**.

---

## Requirements

* A modern browser with WebM support (Chrome, Firefox, Edge)
* Some `.webm` files to play

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---