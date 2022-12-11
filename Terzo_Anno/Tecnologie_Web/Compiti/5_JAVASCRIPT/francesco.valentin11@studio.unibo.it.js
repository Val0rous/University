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

// Hide all images
for (const image of images) {
    image.style.display = "none";
}

// Set first image as current
setCurrent(images[0]);

// Add event listener to each image
for (const image of images) {
    image.addEventListener("click", function() {
        handleClick(image);
    });
}

/** Specify what to do when a click event strikes */
function handleClick(image) {
    if (image.classList.contains("current")) {
        // Do nothing
    } else {
        //TODO: simplify functions being called
        setCurrent(image);
        hideAllImages();
        showImages(image);
    }
}

/**
 * Switches current image, removing "current" class from the element that held it beforehand and setting it to another image
 */ 
function setCurrent(image) {
    if (image.previousElementSibling !== null) {
        image.classList.remove("current");
    }
    if (image.nextElementSibling !== null) {
        image.classlist.remove("current");
    }
    image.classList.add("current");
}

/** Hide all images */
function hideAllImages() {
    for (const image of images) {
        image.style.display = "none";
    }
}
//TODO: improve image switching by using DOM navigation instead of current bruteforcing technique
/** Show previous and following images of given one, if they exist */
function showImages(image) {
    var index = getIndex(image, images);
    images[index].style.display = "inline-block";
    // Previous image
    if ((index-1) >= 0) {
        images[index-1].style.display = "inline-block";
    }
    // Following image
    if ((index+1) < images.length) {
        images[index+1].style.display = "inline-block";
    }
}

//TODO: make this function useless by not using it anymore
/** Gets index of element in array. Returns -1 if element does not exist */
function getIndex(element, array) {
    for (let i=0; i<array.length; i++) {
        if (array[i] === element) {
            return i;
        }
    }
    return -1;
}
