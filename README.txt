Image Processor - manipulate images to create an output image, similar to photoshop. 
Created for Programming Fundamentals 2.

How to run locally on Windows:
1. Download files from this GitHub.
2. Open terminal and cd to the folder the files are in. This is the folder with input, output, src, makefile, and readme.
3. Type make, then hit enter, in the terminal. This will compile the project code.
4. Type .\project.out --help for command formats.
5. For the output image argument, type output/name.tga. For the input image argument(s), type input/name.tga.
You come up with the output name. All the sample input image names are listed in the input folder.
6. Once you enter a command, your output .tga file will appear in the output folder. You can view it with a TGA viewer or with the Windows Media Player.

Possible methods:
 multiply:   This  method  takes  one  additional  argument,  the  second  image  to  use  in  the  multipli- 
cation  process,  alongside  your  tracking  image.
• subtract: This method takes one additional argument, the second image to use in the subtract 
algorithm, alongside your tracking image. The first image, the tracking image, will be the top 
layer. The additional image argument constitutes the bottom layer.
• overlay: This method takes one additional argument, the second image to use in the overlay 
algorithm, alongside your tracking image. The first image, the tracking image, will be the top 
layer. The additional image argument constitutes the bottom layer.
• screen: This method takes one additional argument, the second image to use in the screen 
algorithm, alongside your tracking image. The first image, the tracking image, will be the bottom 
layer. The additional image argument constitutes the top layer.
• combine: This method is similar to what you did in task 9 of Part 2, where three individual files 
each provide one channel of the resulting image. This method takes two additional arguments, the 
source for the green layer (the first additional argument), and the source for the blue layer (the 
second additional argument). The source for the red layer is the tracking image.
• flip:   This  method  takes  no  additional  argument,  and  simply  flips  the  tracking  image.
• onlyred:   This  method  takes  no  additional  arguments,  and  simply  retrieves  the  red  channel  from 
the  image,  similar  to  how  you  did  in  task  8.
• onlygreen:   This  method  takes  no  additional  arguments,  and  simply  retrieves  the  green  channel 
from  the  image,  similar  to  how  you  did  in  task  8.
• onlyblue:    This   method   takes   no   additional   arguments,   and   simply   retrieves   the   blue   channel 
from  the  image,  similar  to  how  you  did  in  task  8.
• addred: This method adds a certain value to the red channel of an image. This method takes one 
additional argument, the amount to add to the red channel. This will need to be converted to an 
integer.
• addgreen: This method adds a certain value to the green channel of an image. This method takes 
one additional argument, the amount to add to the red channel. This will need to be converted to 
an integer.
• addblue: This method adds a certain value to the blue channel of an image. This method takes 
one additional argument, the amount to add to the red channel. This will need to be converted to 
an integer.
• scalered:    This   method   scales   the   red   channel   of   an   image.    This   method   takes   one   additional argument,  the  amount  to  scale  the  red  channel.   This  will  need  to  be  converted  to  an  integer.
• scalegreen:   This method scales the green channel of an image.   This method takes one additional 
argument,  the  amount  to  scale  the  red  channel.   This  will  need  to  be  converted  to  an  integer.
• scaleblue:   This  method  scales  the  blue  channel  of  an  image.   This  method  takes  one  additional 
argument,  the  amount  to  scale  the  red  channel.   This  will  need  to  be  converted  to  an  integer.