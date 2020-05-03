CC = clang
CXX = clang++
MKDIR = mkdir -p
SRC_DIR = ../source
WWISE_SDK_DIR = ../sdks/wwise_2017.2.2.6553/SDK/include/
PATCH_NAME = windGen
OUT_DIR = ../build/linux/x64/release
BASEFLAGS = -I$(WWISE_SDK_DIR) -I$(SRC_DIR) -I$(SRC_DIR)/include -I$(SRC_DIR)/heavy -DNDEBUG -msse4.1 -O3 -ffast-math -fPIC -Werror -Wno-unused-function -Wno-\#warnings
CFLAGS = $(BASEFLAGS) -std=c11
CXXFLAGS = $(BASEFLAGS) -std=c++11 -fno-exceptions -fno-rtti

HEADERS = $(wildcard $(SRC_DIR)/include/*.h)
HEADERS += $(wildcard $(SRC_DIR)/heavy/*.h)
HEADERS += $(wildcard $(SRC_DIR)/engine/*.h)

CFILES = $(wildcard $(SRC_DIR)/heavy/*.c)
OBJC = $(CFILES:%.c=%.o)

CXXFILES = $(wildcard $(SRC_DIR)/engine/*.cpp)
CXXFILES += $(wildcard $(SRC_DIR)/heavy/*.cpp)
OBJCXX = $(CXXFILES:%.cpp=%.o)

RUNTIME_CXXFILES = $(CXXFILES)
RUNTIME_CXXFILES += $(wildcard $(SRC_DIR)/runtime/*.cpp)
RUNTIME_OBJCXX = $(RUNTIME_CXXFILES:%.cpp=%.o)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: directories engine runtime

directories: $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR) $(OUT_DIR)

engine: $(OBJC) $(OBJCXX)
	ar -cvq $(OUT_DIR)/libHv_$(PATCH_NAME)_WwiseSourceEngine.a $^
	cp $(SRC_DIR)/include/Hv_$(PATCH_NAME)_WwiseSourcePluginFactory.h $(OUT_DIR)
	cp ../resources/Hv_$(PATCH_NAME)_WwiseSourceAuthPlugin.xml $(OUT_DIR)

runtime: $(OBJC) $(RUNTIME_OBJCXX)
	$(CXX) -o $(OUT_DIR)/Hv_$(PATCH_NAME)_WwiseSourcePlugin.so $^ $(CXXFLAGS) -shared

.PHONY: clean

clean:
	rm -rf $(SRC_DIR)/**/*.o $(OUT_DIR)/*.*
