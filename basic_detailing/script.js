/*******************************************************
  main func
*******************************************************/
document.addEventListener("DOMContentLoaded", function () {
  init_banner_rotation();
  init_satisfaction_logic();
});

/*******************************************************
   6 imgs rotating
*******************************************************/
function init_banner_rotation() {
  const slides = document.querySelectorAll(".banner_slide");
  const interval_time = 3000;
  let current_slide_index = 0;

  if (slides.length === 0) {
    return;
  }

  function show_next_slide() {
    // rmove active class from current
    slides[current_slide_index].classList.remove("active");

    // incr index
    current_slide_index = current_slide_index + 1;

    // reset if end is reached
    if (current_slide_index === slides.length) {
      current_slide_index = 0;
    }

    // set the next
    slides[current_slide_index].classList.add("active");
  }

  setInterval(show_next_slide, interval_time);
}

/*******************************************************
   satisfaction emotes
*******************************************************/
function init_satisfaction_logic() {
  const slider = document.getElementById("satisfaction_slider");
  const emojis = document.querySelectorAll(".emoji_item");

  if (slider === null || emojis.length === 0) {
    return;
  }

  function update_emoji_display(val) {
    emojis.forEach(function (emoji) {
      const emoji_val = emoji.getAttribute("data-val");

      // compare type and value
      if (emoji_val === val) {
        emoji.classList.add("active");
      } else {
        emoji.classList.remove("active");
      }
    });
  }

  // listner for slider
  slider.addEventListener("input", function (event) {
    const current_val = event.target.value;
    update_emoji_display(current_val);
  });

  // fix for the initial slide display
  update_emoji_display(slider.value);
}
