CC = g++
LIBS = -lGL -lGLU -lGLEW -lglut

main : main.cpp InitAntix.o InitGlew.o ShaderManager.o SceneManager.o Model.o Triangle.o ModelsManager.o Quad.o
	$(CC) main.cpp -o main InitAntix.o InitGlew.o ShaderManager.o SceneManager.o Model.o Triangle.o ModelsManager.o Quad.o $(LIBS)

InitGlew.o : InitGlew.cpp
	$(CC) -c InitGlew.cpp -o InitGlew.o $(LIBS)

InitAntix.o : InitAntix.cpp InitGlew.o
	$(CC) -c InitAntix.cpp -o InitAntix.o InitGlew.o $(LIBS)

ShaderManager.o : ShaderManager.cpp 
	$(CC) -c ShaderManager.cpp -o ShaderManager.o $(LIBS)

SceneManager.o : SceneManager.cpp ShaderManager.o
	$(CC) -c SceneManager.cpp -o SceneManager.o ShaderManager.o $(LIBS)

Model.o : Model.cpp
	$(CC) -c Model.cpp -o Model.o $(LIBS)

Triangle.o : Triangle.cpp Model.o
	$(CC) -c Triangle.cpp -o Triangle.o $(LIBS)

Quad.o : Quad.cpp Model.o
	$(CC) -c Quad.cpp -o Quad.o $(LIBS)

ModelsManager.o : ModelsManager.cpp ShaderManager.o Triangle.o
	$(CC) -c ModelsManager.cpp -o ModelsManager.o $(LIBS)

clean :
	rm main InitGlew.o InitAntix.o ShaderManager.o Model.o Triangle.o ModelsManager.o SceneManager.o Quad.o