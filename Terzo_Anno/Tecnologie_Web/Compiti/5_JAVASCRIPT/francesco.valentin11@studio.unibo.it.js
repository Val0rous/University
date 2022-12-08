"use strict";

const images = window.document.images;

// Hide all images but the first two ones
for (let i=2; i<images.length; i++) {
    images[i].style.display = "none";
}

// Add "current" class to first image
setCurrent(images[0]);

// Add event listener to each image
for (const image of images) {
    image.addEventListener("click", function() {
        handleClick(image);
    });
}

// Specify what to do when a click event strikes
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

// Set "current" class to an image
function setCurrent(image) {
    image.classList.add("current");
}

// Remove "current" class from all images
function removeAllCurrent() {
    for (const image of images) {
        image.classList.remove("current");
    }
}

// Hide all images
function hideAllImages() {
    for (const image of images) {
        image.style.display = "none";
    }
}

// Show previous and following images of given one, if they exist
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

// Gets index of element in array. Returns -1 if element does not exist
function getIndex(element, array) {
    for (let i=0; i<array.length; i++) {
        if (array[i] === element) {
            return i;
        }
    }
    return -1;
}
