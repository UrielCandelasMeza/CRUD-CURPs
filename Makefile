CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I.
TARGET   := main
OBJ_DIR  := build

# Lista de archivos fuente
SRCS := main.cpp curp/curp.cpp

# Genera los paths de los objetos: build/main.o build/curp/curp.o
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Regla principal
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o dentro de build/
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza total
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean
