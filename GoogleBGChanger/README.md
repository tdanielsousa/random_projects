# Google BG Change

A Chrome extension (Manifest V3) that changes the background color of Google's dark mode to a custom shade (`#252527`) on Google pages.

Since recent updates google changed their Dark Mode color to a blue-ish tint, which on WCG screens looks awfull, this simple extension fixes that.

> Disclaimer: This extension overrides CSS variables and class names that Google generates (such as `--xhUGwc` and `.RDmXvc`). 
Those names are internal and can change at any time, so the extension may stop working after a Google update.
---

##  How It Works

The extension injects a stylesheet into Google pages as early as possible, so the color is applied before the page renders.

### Technical Specifications
* **Manifest Version:** 3.
* **Content Script:** Injects `style.css` on matching pages at `document_start`.
* **Matched Sites:** `https://*.google.com/*` and `https://*.google.pt/*`.
* **No JavaScript:** The whole extension is a manifest and a single CSS file.

### The Stylesheet
* **Variable Override (`--xhUGwc`):** Sets Google's dark mode background variable to `#252527` on every element, using `!important` to win over Google's own styles.
* **Gradient Fix (`.RDmXvc`):** Replaces the fade gradient with one that ends in the same `#252527` color (`#2525278c` at 52px), so there is no visible mismatch at the edges.

---

##  Customization

To use a different color, replace `#252527` in `style.css`. For the gradient, the semi-transparent value (`#2525278c`) must use the same color with an alpha suffix, otherwise the fade will not blend correctly.

---

## Installation & Run Steps

### 1. Download the Files
Make sure `manifest.json` and `style.css` are in the same folder.

### 2. Open the Extensions Page
In Chrome (or any Chromium browser), go to:

    chrome://extensions

### 3. Load the Extension
Turn on **Developer mode**, click **Load unpacked**, and select the folder containing the files.

### 4. Enable Google Dark Mode
The extension only changes the dark mode color, so make sure dark mode is active on Google (or in your browser/OS settings).

---

## Requirements

* A Chromium-based browser (Chrome, Edge, Brave, etc.)
* Google dark mode enabled

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---