CXX = g++
CXXFLAGS = -std=c++11 -Wall
EXECUTABLE = authentication_test

SRC_DIR = headers/authentication
TEST_DIR = testing/authenticationTesting
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TEST_FILE = $(TEST_DIR)/authenticationTesting.cpp

$(EXECUTABLE): $(OBJ_FILES) $(TEST_FILE)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(TEST_FILE) -o $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/authentication.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
