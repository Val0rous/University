"use strict";

/**
 * Array of all images inside the slider
 */
const images = Array();

// Add only images inside the div having class="slider-image"
for (let i = 0; i < document.images.length; i++) {
    if (document.images.item(i).parentElement ===
        document.getElementsByClassName("slider-image").item(0)) {
        images.push(document.images.item(i));
    }
}

// Hide all images but the first two ones
for (let i = 2; i < images.length; i++) {
    images[i].style.display = "none";
}

// Add "current" class to first image
setCurrent(images[0]);

// Add event listener to each image
for (const image of images) {
    image.addEventListener("click", function () {
        handleClick(image);
    });
}

/**
 * Specify what to do when a click event strikes
 * @param image - the image that has been clicked
 */
function handleClick(image) {
    if (image.classList.contains("current")) {
        // Do nothing
    } else {
        removeAllCurrent();
        setCurrent(image);
        hideAllImages();
        showImages(image);
    }
}

/**
 * Set "current" class to an image
 * @param image - the image that is going to be set as current
 */
function setCurrent(image) {
    image.classList.add("current");
}

/**
 * Remove "current" class from all images
 */
function removeAllCurrent() {
    for (const image of images) {
        image.classList.remove("current");
    }
}

/**
 * Hide all images
 */
function hideAllImages() {
    for (const image of images) {
        image.style.display = "none";
    }
}

/**
 * Show previous and following images of given one, if they exist
 * @param image - current image
 */
function showImages(image) {
    var index = images.indexOf(image);
    images[index].style.display = "inline-block";
    // Previous image
    if ((index - 1) >= 0) {
        images[index - 1].style.display = "inline-block";
    }
    // Following image
    if ((index + 1) < images.length) {
        images[index + 1].style.display = "inline-block";
    }
}
