"use strict";

/** Array of all images inside the slider */
const images = Array();

// Add only images inside the div having class="slider-image"
for (let i=0; i<document.images.length; i++) {
    if (document.images.item(i).parentElement === 
    document.getElementsByClassName("slider-image").item(0)) {
        images.push(document.images.item(i));
    }
}

// Add event listener to each image
for (const image of images) {
    image.addEventListener("click", function() {
        handleClick(image);
    });
}

// Hide all images
for (const image of images) {
    image.style.display = "none";
}

// Set first image as current
setCurrent(images[0]);

/** 
 * Specify what to do when a click event strikes
 * @param image - the image that is being clicked
 */
function handleClick(image) {
    if (image.classList.contains("current")) {
        // Do nothing
    } else {
        //TODO: simplify functions being called
        setCurrent(image);
    }
}

/**
 * Switches current image, removing "current" class from the element that held it beforehand and setting it to another image
 * @param image - the image that is going to be set as current
 */ 
function setCurrent(image) {
    if (image.previousElementSibling !== null) {
        image.previousElementSibling.classList.remove("current");
    }
    if (image.nextElementSibling !== null) {
        image.nextElementSibling.classlist.remove("current");
    }
    image.classList.add("current");
    showImages(image);
}

/** Hide images that are not next to the current one */
function hideImages(image) {
    if (image.previousElementSibling.previousElementSibling !== null) {
        image.previousElementSibling.previousElementSibling.style.display = "none";
    }
    if (image.nextElementSibling.nextElementSibling !== null) {
        image.nextElementSibling.nextElementSibling.style.display = "none";
    }
}

//TODO: improve image switching by using DOM navigation instead of current bruteforcing technique
/** Show previous and following images of given one, if they exist */
function showImages(image) {
    image.style.display = "inline-block";
    // Previous image
    if (image.previousElementSibling !== null) {
        image.previousElementSibling.style.display = "inline-block";
    }
    // Next image
    if (image.nextElementSibling !== null) {
        image.nextElementSibling.style.display = "inline-block";
    }
    hideImages(image);
}
