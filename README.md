### How to run this program
#### Step 01: Clone this repo to your location
```
git clone git@github.com:snandasena/opencv-cmake-config.git
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
