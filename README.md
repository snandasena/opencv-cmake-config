### How to run this program
#### Step 01: Clone this repo to your location
```
git clone git@github.com:snandasena/opencv-cpp-examples.git
```
#### Step 02: Create a build directory
```
cd opencv-cmake-config
mkdir build
```
#### Step 03(First time only): Change directoy and build the project
```
cd build
cmake ../src/
```
#### Step 04: Build the executable
```
cd ../
cmake --build build --target opencvdemo  -- -j4
```
#### Step 05: Run the executable
```
./build/opencvdemo
```

#### Notice:
**There are multiple c++ files in src folder and if you want to try those, please un comment required file from CMakeLists.txt and run it.**

#### Acknowledgement

Please visit [OpenCV](https://docs.opencv.org/4.3.0/d9/df8/tutorial_root.html) 
