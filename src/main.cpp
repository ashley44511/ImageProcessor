#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring> // This for strcmp
#include <stdexcept> // Error handling
#include "image.h"
using namespace std;
/*
 * 1. Remember to clamp values
 * 2. Normalizing values
 * float Normalize(int value) {
 * return (value / 255.0f);
 * }
 * 3. Create your own comparison function
 * to figure out if you images actually do match
 * check header elements and pixels
 * if(this->idLength != image.idLength) {return false;}
 * ect
 * 4. Import example and input folders all at once - in the beginning of the main
 * Image example1 = readFile("examples/EXAMPLE_part1.tga");
 * Image layer1 = readFile("input/layer1.tga");
 * then you can use them in your comparison function
 *
 * 5. First pixel in the series represents the bottom left corner and final is upper right corner
 *
 * 6. Functions should pass by reference, not by values
 *
 * 7. Use is_open()
 *
 * 8. Try write the images without manipulation to the output folder first to make sure read/write is done correctly
 *
 * 9. Make test cases as functions LAST
 *
 */

/*
void ScaleBlue(Image &image, int value) {
    for(unsigned int i = 0; i < image.pixelVect.size(); i++) {
        int b = image.pixelVect[i].blue;
        b *= value;
        image.pixelVect[i].blue = (unsigned char)Clamp(b);
    }
}
*/
/*
//Task 1 (Multiply)
Image layer1_1;
layer1_1.read("input/layer1.tga");
Image pattern1_1;
pattern1_1.read("input/pattern1.tga");
layer1_1.Multiply(pattern1_1);
layer1_1.write("output/part1.tga");
//testing

Image example1;
example1.read("examples/EXAMPLE_part1.tga");
Image output1;
output1.read("output/part1.tga");
output1.Compare(example1);


//Task 2 (Subtract)
Image layer2_2;
layer2_2.read("input/layer2.tga");
Image car_2;
car_2.read("input/car.tga");
car_2.Subtract(layer2_2);
car_2.write("output/part2.tga");
//testing

Image example2;
example2.read("examples/EXAMPLE_part2.tga");
Image output2;
output2.read("output/part2.tga");
output2.Compare(example2);


//Task 3 (Multiply-Screen)
Image layer1_3;
layer1_3.read("input/layer1.tga");
Image pattern2_3;
pattern2_3.read("input/pattern2.tga");
layer1_3.Multiply(pattern2_3);
Image text_3;
text_3.read("input/text.tga");
layer1_3.Screen(text_3);
layer1_3.write("output/part3.tga");
//testing

Image example3;
example3.read("examples/EXAMPLE_part3.tga");
Image output3;
output3.read("output/part3.tga");
output3.Compare(example3);


//Task 4 (Multiply-Subtract)
Image layer2_4;
layer2_4.read("input/layer2.tga");
Image circles_4;
circles_4.read("input/circles.tga");
layer2_4.Multiply(circles_4);
Image pattern2_4;
pattern2_4.read("input/pattern2.tga");
layer2_4.Subtract(pattern2_4);
layer2_4.write("output/part4.tga");
//testing

Image example4;
example4.read("examples/EXAMPLE_part4.tga");
Image output4;
output4.read("output/part4.tga");
output4.Compare(example4);


//Task 5 (Overlay)
Image layer1_5;
layer1_5.read("input/layer1.tga");
Image pattern1_5;
pattern1_5.read("input/pattern1.tga");
layer1_5.Overlay(pattern1_5);
layer1_5.write("output/part5.tga");
//testing

Image example5;
example5.read("examples/EXAMPLE_part5.tga");
Image output5;
output5.read("output/part5.tga");
output5.Compare(example5);


//Task 6 (add 200 green)
Image car_6;
car_6.read("input/car.tga");
car_6.SpecificAdd(200, "green");
car_6.write("output/part6.tga");
//testing

Image example6;
example6.read("examples/EXAMPLE_part6.tga");
Image output6;
output6.read("output/part6.tga");
output6.Compare(example6);


//Task 7 (multiply red by 4, blue by 0)
Image car_7;
car_7.read("input/car.tga");
car_7.SpecificMultiply(4, "red");
car_7.SpecificMultiply(0, "blue");
car_7.write("output/part7.tga");
//testing

Image example7;
example7.read("examples/EXAMPLE_part7.tga");
Image output7;
output7.read("output/part7.tga");
output7.Compare(example7);


//Task 8 (write each channel to a separate file)
Image r_8;
r_8.read("input/car.tga");
r_8.BlackAndWhite("red");
r_8.write("output/part8_r.tga");
Image g_8;
g_8.read("input/car.tga");
g_8.BlackAndWhite("green");
g_8.write("output/part8_g.tga");
Image b_8;
b_8.read("input/car.tga");
b_8.BlackAndWhite("blue");
b_8.write("output/part8_b.tga");
//testing

Image example8_r;
example8_r.read("examples/EXAMPLE_part8_r.tga");
Image output8_r;
output8_r.read("output/part8_r.tga");
output8_r.Compare(example8_r);
Image example8_g;
example8_g.read("examples/EXAMPLE_part8_g.tga");
Image output8_g;
output8_g.read("output/part8_g.tga");
output8_g.Compare(example8_g);
Image example8_b;
example8_b.read("examples/EXAMPLE_part8_b.tga");
Image output8_b;
output8_b.read("output/part8_b.tga");
output8_b.Compare(example8_b);


//Task 9 (load red, green, and blue files and combine into one file)
Image layer_red_9;
layer_red_9.read("input/layer_red.tga");
Image layer_green_9;
layer_green_9.read("input/layer_green.tga");
Image layer_blue_9;
layer_blue_9.read("input/layer_blue.tga");
layer_red_9.ReplaceChannel(layer_green_9, "green");
layer_red_9.ReplaceChannel(layer_blue_9, "blue");
layer_red_9.write("output/part9.tga");
//testing

Image example9;
example9.read("examples/EXAMPLE_part9.tga");
Image output9;
output9.read("output/part9.tga");
output9.Compare(example9);


//Task 10 (rotate image 180 degrees aka upside down)
Image text2_10;
text2_10.read("input/text2.tga");
text2_10.UpsideDown();
text2_10.write("output/part10.tga");
//testing

Image example10;
example10.read("examples/EXAMPLE_part10.tga");
Image output10;
output10.read("output/part10.tga");
output10.Compare(example10);
*/
bool checkTga(char* argv[], int argIndex) {
    string tgaCheck = ".tga";
    //int tgaLength = tgaCheck.length();
    //int argvILength = argv[1].length();
    int j = 0;
    int argvILength = 0;
    //argv[i][j] != '\0'
    char variable = argv[argIndex][j];
    while (argv[argIndex][j] != '\0') {
        argvILength++;
        j++;
        variable = argv[argIndex][j];
    }
    argvILength++; //for \0
    if ((argvILength > 5) && (tgaCheck[3] == argv[argIndex][argvILength - 2]) && (tgaCheck[2] == argv[argIndex][argvILength - 3]) && (tgaCheck[1] == argv[argIndex][argvILength - 4]) && (tgaCheck[0] == argv[argIndex][argvILength - 5])) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {

    /*
    Image ex15;
    ex15.read("input/car.tga");
    Image subtractLayer;
    subtractLayer.read("input/layer1.tga");
    ex15.Subtract(subtractLayer);
    Image multiplyLayer;
    multiplyLayer.read("input/circles.tga");
    ex15.Multiply(multiplyLayer);
    ex15.UpsideDown();
    ex15.write("output/task15ex.tga");

    Image task15test;
    task15test.read("output/part15test07.tga");

    ex15.Compare(task15test);
    */
    //int nextStep = -1; //0 - help, 1 - it is tga
    if ((argc <= 1) || (strcmp(argv[1], "--help") == 0)) {
        //nextStep = 0;
        cout << "Project 2: Image Processing, Fall 2023" << endl << endl;
        cout << "Usage:" << endl;
        cout << "\t./project2.out [output] [firstImage] [method] [...]" << endl;
    } else {
        /*
         * NOW IN CHECKTGA()
        string tgaCheck = ".tga";
        //int tgaLength = tgaCheck.length();
        //int argv1Length = argv[1].length();
        int j = 0;
        int argv1Length = 0;
        //argv[i][j] != '\0'
        while (argv[1][j] != '\0') {
            argv1Length++;
            j++;
        }
        argv1Length++; //for \0
         */
        //TODO
        /*
        for (int is = 0; is < 5; is++) {
            cout << is << " " << argv[is] << endl;
        }
         */

        int goToNextArg = -1;
        if (checkTga(argv, 1)) {
            //cout << "This is a .tga file" << endl; //TODO
            goToNextArg = 1;
        } else {
            cout << "Invalid file name." << endl;
            //cout << argv[1] << endl; //TODO
            goToNextArg = 0;
        }
        /*
        The second argument will be the name of the source file for your tracking image. If this argument is
        not provided, or if the argument does not end with .tga, print "Invalid file name." If the filename
        is not a real file, then print "File does not exist." */
        if (goToNextArg == 1) {
            if(argc > 2) { //has executable as first argument, output.tga as second argument
                if (checkTga(argv, 2)) { //checking 3rd argument is .tga file
                    //cout << "This is a .tga file" << endl;
                    goToNextArg = 1; //go to line 298
                } else {
                    cout << "Invalid file name." << endl;
                    goToNextArg = 0;
                }
            } else {
                cout << "Invalid file name." << endl;
                goToNextArg = 0;
            }
            /*The third argument will be the name of the first image manipulation method. If this argument
            is not provided, or if the method does not exist, print "Invalid method name." */
            if (goToNextArg == 1) {
                Image trackingImg;
                trackingImg.readSRC(argv[2]);
                Image secondImg;
                Image thirdImg;
                int nextArgIndex = -1;
                if (argc > 3) {
                    if ((strcmp(argv[3], "multiply") == 0) || (strcmp(argv[3], "subtract") == 0) || (strcmp(argv[3], "overlay") == 0) || (strcmp(argv[3], "screen") == 0)) {
                        if ((argc > 4) && checkTga(argv, 4)) { //file argument argv[4]
                            //read second img
                            //Image secondImg;
                            secondImg.read(argv[4]);
                            //actually alter img
                            if (strcmp(argv[3], "multiply") == 0) { //one additional argument
                                //This method takes one additional argument, the second image to use in the multipli-
                                //cation process, alongside your tracking image.
                                //actually multiply
                                cout << "Multiplying " << argv[2] << " and " << argv[4] << " ... " << endl;
                                trackingImg.Multiply(secondImg);
                            } else if (strcmp(argv[3], "subtract") == 0) {
                                //This method takes one additional argument, the second image to use in the subtract alg, alongside your tracking image.
                                //tracking img is top
                                cout << "Subtracting " << argv[2] << " and " << argv[4] << " ... " << endl;
                                trackingImg.Subtract(secondImg);
                            } else if (strcmp(argv[3], "overlay") == 0) {
                                cout << "Overlaying " << argv[2] << " and " << argv[4] << " ... " << endl;
                                trackingImg.Overlay(secondImg);
                            } else if (strcmp(argv[3], "screen") == 0) {
                                //tracking img is bottom layer
                                //second image is top layer
                                //TODO i don't think layer matters for this
                                cout << "Screening " << argv[2] << " and " << argv[4] << " ... " << endl;
                                trackingImg.Screen(secondImg);
                            }

                            if(argc > 5) {
                                goToNextArg = 1;
                                nextArgIndex = 5; //use for while loop
                            } else {
                                goToNextArg = 63; //not going to next arg, but writing to file so dif from 0
                            }
                        } else if (argc <= 4) {
                            cout << "Missing argument." << endl;
                            goToNextArg = 0;
                        } else {
                            cout << "Invalid argument, invalid file name." << endl;
                            goToNextArg = 0;
                        }
                    } else if ((strcmp(argv[3], "combine") == 0)) {
                        if ((argc > 5) && checkTga(argv, 4) && checkTga(argv, 5)) { //file argument argv[4]
                            //read second img
                            //Image secondImg;
                            secondImg.read(argv[4]);
                            //read third img
                            //Image thirdImg;
                            thirdImg.read(argv[5]);
                            //actually alter img
                            //argv4 is source for green layer, argv5 is source for blue layer
                            //argv2 is source for red layer
                            cout << "Combining " << argv[2] << " and " << argv[4] << " and " << argv[5] << " ... " << endl;
                            trackingImg.ReplaceChannel(secondImg, "green");
                            trackingImg.ReplaceChannel(thirdImg, "blue");

                            if(argc > 6) {
                                goToNextArg = 1;
                                nextArgIndex = 6;
                            } else {
                                goToNextArg = 63;
                            }
                        } else if (argc <= 5) {
                            cout << "Missing argument." << endl;
                            goToNextArg = 0;
                        } else {
                            cout << "Invalid argument, invalid file name." << endl;
                            goToNextArg = 0;
                        }
                    } else if ((strcmp(argv[3], "flip") == 0) || (strcmp(argv[3], "onlyred") == 0) || (strcmp(argv[3], "onlygreen") == 0) || (strcmp(argv[3], "onlyblue") == 0)) {
                        if (strcmp(argv[3], "flip") == 0) {
                            trackingImg.UpsideDown();
                            cout << "Flipping " << argv[2] << " ... " << endl;
                        } else if (strcmp(argv[3], "onlyred") == 0) {
                            //Task 8 (write each channel to a separate file)
                            trackingImg.BlackAndWhite("red");
                            cout << "Using only red on " << argv[2] << " ... " << endl;
                        } else if (strcmp(argv[3], "onlygreen") == 0) {
                            trackingImg.BlackAndWhite("green");
                            cout << "Using only green on " << argv[2] << " ... " << endl;
                        } else {
                            trackingImg.BlackAndWhite("blue");
                            cout << "Using only blue on " << argv[2] << " ... " << endl;
                        }

                        if(argc > 4) {
                            goToNextArg = 1;
                            nextArgIndex = 4;
                        } else {
                            goToNextArg = 63;
                        }
                    } else if ((strcmp(argv[3], "addred") == 0) || (strcmp(argv[3], "addgreen") == 0) || (strcmp(argv[3], "addblue") == 0) || (strcmp(argv[3], "scalered") == 0) || (strcmp(argv[3], "scalegreen") == 0) || (strcmp(argv[3], "scaleblue") == 0)) {
                        if (argc > 4) {
                            try {
                                int num = stoi(argv[4]);
                                if (strcmp(argv[3], "addred") == 0) {
                                    //Task 6
                                    trackingImg.SpecificAdd(num, "red");
                                    cout << "Adding red +" << num << " to " << argv[2] << " ... " << endl;
                                } else if (strcmp(argv[3], "addgreen") == 0) {
                                    trackingImg.SpecificAdd(num, "green");
                                    cout << "Adding green +" << num << " to " << argv[2] << " ... " << endl;
                                } else if (strcmp(argv[3], "addblue") == 0) {
                                    trackingImg.SpecificAdd(num, "blue");
                                    cout << "Adding blue +" << num << " to " << argv[2] << " ... " << endl;
                                } else if (strcmp(argv[3], "scalered") == 0) {
                                    //Task 7
                                    trackingImg.SpecificMultiply(num, "red");
                                    cout << "Scaling red by " << num << " for " << argv[2] << " ... " << endl;
                                } else if (strcmp(argv[3], "scalegreen") == 0) {
                                    trackingImg.SpecificMultiply(num, "green");
                                    cout << "Scaling green by " << num << " for " << argv[2] << " ... " << endl;
                                } else { //scaleblue
                                    trackingImg.SpecificMultiply(num, "blue");
                                    cout << "Scaling blue by " << num << " for " << argv[2] << " ... " << endl;
                                }

                                if(argc > 5) {
                                    goToNextArg = 1;
                                    nextArgIndex = 5;
                                } else {
                                    goToNextArg = 63;
                                }
                            }
                            catch (const invalid_argument &e) {
                                cout << "Invalid argument, expected number." << endl;
                            }
                            catch (const out_of_range &e) {
                                cout << "Invalid argument, expected number." << endl;
                            }
                        } else {
                            cout << "Missing argument." << endl;
                            goToNextArg = 0;
                        }

                    } else {
                        cout << "Invalid method name." << endl;
                        goToNextArg = 0;
                    }

                    while (goToNextArg == 1) {
                        Image* repeatedImg2;
                        repeatedImg2 = new Image;
                        Image* repeatedImg3;
                        repeatedImg3 = new Image;
                        if ((strcmp(argv[nextArgIndex], "multiply") == 0) || (strcmp(argv[nextArgIndex], "subtract") == 0) || (strcmp(argv[nextArgIndex], "overlay") == 0) || (strcmp(argv[nextArgIndex], "screen") == 0)) {
                            if ((argc > nextArgIndex + 1) && checkTga(argv, nextArgIndex + 1)) { //file argument argv[4]; 4 is now nextArgIndex
                                //read second img
                                //Image secondImg;
                                repeatedImg2->read(argv[nextArgIndex + 1]);
                                //actually alter img
                                if (strcmp(argv[nextArgIndex], "multiply") == 0) { //one additional argument
                                    //This method takes one additional argument, the second image to use in the multipli-
                                    //cation process, alongside your tracking image.
                                    //actually multiply
                                    cout << "... and multiplying output of previous step and " << argv[nextArgIndex + 1] << " ... " << endl;
                                    trackingImg.Multiply(*repeatedImg2);
                                } else if (strcmp(argv[nextArgIndex], "subtract") == 0) {
                                    //This method takes one additional argument, the second image to use in the subtract alg, alongside your tracking image.
                                    //tracking img is top
                                    cout << "... and subtracting " << argv[nextArgIndex + 1] << " from previous step ... " << endl;
                                    trackingImg.Subtract(*repeatedImg2);
                                } else if (strcmp(argv[nextArgIndex], "overlay") == 0) {
                                    cout << "... and overlaying " << argv[nextArgIndex + 1] << " on previous step ... " << endl;
                                    trackingImg.Overlay(*repeatedImg2);
                                } else if (strcmp(argv[nextArgIndex], "screen") == 0) {
                                    //tracking img is bottom layer
                                    //second image is top layer
                                    //TODO i don't think layer matters for this
                                    cout << "... and screening " << argv[nextArgIndex + 1] << " on previous step ... " << endl;
                                    trackingImg.Screen(*repeatedImg2);
                                }

                                if(argc > nextArgIndex + 2) {
                                    goToNextArg = 1;
                                    nextArgIndex += 2;
                                } else {
                                    goToNextArg = 63;
                                }
                            } else if (argc <= nextArgIndex + 1) {
                                cout << "Missing argument." << endl;
                                goToNextArg = 0;
                            } else {
                                cout << "Invalid argument, invalid file name." << endl;
                                goToNextArg = 0;
                            }
                        } else if ((strcmp(argv[nextArgIndex], "combine") == 0)) {
                            if ((argc > nextArgIndex + 2) && checkTga(argv, nextArgIndex + 1) && checkTga(argv, nextArgIndex + 2)) { //file argument argv[4]
                                //read second img
                                //Image secondImg;
                                repeatedImg2->read(argv[nextArgIndex + 1]);
                                //read third img
                                //Image thirdImg;
                                repeatedImg3->read(argv[nextArgIndex + 2]);
                                //actually alter img
                                //argv4 is source for green layer, argv5 is source for blue layer
                                //argv2 is source for red layer
                                trackingImg.ReplaceChannel(*repeatedImg2, "green");
                                trackingImg.ReplaceChannel(*repeatedImg3, "blue");
                                cout << "Combining previous output and " << argv[nextArgIndex + 1] << " and " << argv[nextArgIndex + 2] << " ... " << endl;

                                if(argc > nextArgIndex + 3) {
                                    goToNextArg = 1;
                                    nextArgIndex += 3;
                                } else {
                                    goToNextArg = 63;
                                }
                            } else if (argc <= 5) {
                                cout << "Missing argument." << endl;
                                goToNextArg = 0;
                            } else {
                                cout << "Invalid argument, invalid file name." << endl;
                                goToNextArg = 0;
                            }
                        } else if ((strcmp(argv[nextArgIndex], "flip") == 0) || (strcmp(argv[nextArgIndex], "onlyred") == 0) || (strcmp(argv[nextArgIndex], "onlygreen") == 0) || (strcmp(argv[nextArgIndex], "onlyblue") == 0)) {
                            if (strcmp(argv[nextArgIndex], "flip") == 0) {
                                trackingImg.UpsideDown();
                                cout << "... flipping previous output" << endl;
                            } else if (strcmp(argv[nextArgIndex], "onlyred") == 0) {
                                //Task 8 (write each channel to a separate file)
                                trackingImg.BlackAndWhite("red");
                                cout << "... using only red on " << argv[2] << " ... " << endl;
                            } else if (strcmp(argv[nextArgIndex], "onlygreen") == 0) {
                                trackingImg.BlackAndWhite("green");
                                cout << "... using only green on " << argv[2] << " ... " << endl;
                            } else {
                                trackingImg.BlackAndWhite("blue");
                                cout << "... using only blue on " << argv[2] << " ... " << endl;
                            }

                            if(argc > nextArgIndex + 1) {
                                goToNextArg = 1;
                                nextArgIndex += 1;
                            } else {
                                goToNextArg = 63;
                            }
                        } else if ((strcmp(argv[nextArgIndex], "addred") == 0) || (strcmp(argv[nextArgIndex], "addgreen") == 0) || (strcmp(argv[nextArgIndex], "addblue") == 0) || (strcmp(argv[nextArgIndex], "scalered") == 0) || (strcmp(argv[nextArgIndex], "scalegreen") == 0) || (strcmp(argv[nextArgIndex], "scaleblue") == 0)) {
                            if (argc > nextArgIndex + 1) {
                                try {
                                    int num = stoi(argv[nextArgIndex + 1]);
                                    if (strcmp(argv[nextArgIndex], "addred") == 0) {
                                        //Task 6
                                        trackingImg.SpecificAdd(num, "red");
                                        cout << "... adding red +" << num << " to previous output ... " << endl;
                                    } else if (strcmp(argv[nextArgIndex], "addgreen") == 0) {
                                        trackingImg.SpecificAdd(num, "green");
                                        cout << "... adding red +" << num << " to previous output ... " << endl;
                                    } else if (strcmp(argv[nextArgIndex], "addblue") == 0) {
                                        trackingImg.SpecificAdd(num, "blue");
                                        cout << "... adding red +" << num << " to previous output ... " << endl;
                                    } else if (strcmp(argv[nextArgIndex], "scalered") == 0) {
                                        //Task 7
                                        trackingImg.SpecificMultiply(num, "red");
                                        cout << "... scaling red by " << num << " for previous output ... " << endl;
                                    } else if (strcmp(argv[nextArgIndex], "scalegreen") == 0) {
                                        trackingImg.SpecificMultiply(num, "green");
                                        cout << "... scaling red by " << num << " for previous output ... " << endl;
                                    } else { //scaleblue
                                        trackingImg.SpecificMultiply(num, "blue");
                                        cout << "... scaling red by " << num << " for previous output ... " << endl;
                                    }

                                    if(argc > nextArgIndex + 2) {
                                        goToNextArg = 1;
                                        nextArgIndex += 2;
                                    } else {
                                        goToNextArg = 63;
                                    }
                                }
                                catch (const invalid_argument &e) {
                                    cout << "Invalid argument, expected number." << endl;
                                }
                                catch (const out_of_range &e) {
                                    cout << "Invalid argument, expected number." << endl;
                                }
                            } else {
                                cout << "Missing argument." << endl;
                                goToNextArg = 0;
                            }

                        } else {
                            cout << "Invalid method name." << endl;
                            goToNextArg = 0;
                        }
                        delete repeatedImg2;
                        delete repeatedImg3;
                    }

                    if (goToNextArg == 63) {
                        cout << "... and saving output to " << argv[1] << "!" << endl;
                        trackingImg.write(argv[1]);
                    }
                } else {
                    cout << "Invalid file name." << endl;
                    goToNextArg = 0;
                }
            }
        }

    }





}

