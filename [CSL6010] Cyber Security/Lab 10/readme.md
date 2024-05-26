# **Lab 10 Programming Assignment**
------------------------------------------

The given `script.py` python script hides an image within a text document using the "docx" library to read and write .docx files, and the "PIL" library to read and process the image.

- The script first reads a .docx file and stores all the words in a string. It then opens an image and gets the size of the image. Next, it creates a new document using the "docx" library and adds a paragraph to the document.

- The script iterates over all the pixels in the image and performs the following steps for each pixel:

    1. Find the corresponding letter from the string of words from the .docx file.
    2. Add the letter to the paragraph in the new document.
    3. Set the color of the letter to the corresponding pixel in the image.

- Finally, the script saves the new document with the hidden image.

- The output document will contain the same text as the original document but with some letters colored according to the image pixels.

> We have also added a progress bar so that we can see how much conversion is done.

## **To run the script**

First make sure all the paths entered are correct.
Then run the file by writing `python script.py` in terminal from root directory.