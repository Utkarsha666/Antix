CC = g++
LIBS = -lGL -lGLU -lGLEW -lglut -lSOIL
LI = ar

main : main.cpp libAntix.a
	$(CC) main.cpp -lm -o main -L. -lAntix $(LIBS)

Antix.o : Antix.cpp InitAntix.o InitGlew.o ShaderManager.o SceneManager.o ModelsManager.o Model.o Quad.o Texture.o Sprite.o Triangle.o
	$(CC) -c Antix.cpp -o Antix.o $(LIBS)

libAntix.a : Antix.o InitAntix.o InitGlew.o ShaderManager.o SceneManager.o ModelsManager.o Model.o Quad.o Texture.o Sprite.o Triangle.o
	ar rcs $@ $+

InitGlew.o : InitGlew.cpp
	$(CC) -c InitGlew.cpp -o InitGlew.o $(LIBS)

InitAntix.o : InitAntix.cpp InitGlew.o
	$(CC) -c InitAntix.cpp -o InitAntix.o $(LIBS)

ShaderManager.o : ShaderManager.cpp 
	$(CC) -c ShaderManager.cpp -o ShaderManager.o $(LIBS)

SceneManager.o : SceneManager.cpp ShaderManager.o
	$(CC) -c SceneManager.cpp -o SceneManager.o $(LIBS)

Model.o : Model.cpp
	$(CC) -c Model.cpp -o Model.o $(LIBS)

Triangle.o : Triangle.cpp Model.o
	$(CC) -c Triangle.cpp -o Triangle.o $(LIBS)

Quad.o : Quad.cpp Model.o
	$(CC) -c Quad.cpp -o Quad.o $(LIBS)

ModelsManager.o : ModelsManager.cpp ShaderManager.o Triangle.o
	$(CC) -c ModelsManager.cpp -o ModelsManager.o $(LIBS)

Texture.o : Texture.cpp
	$(CC) -c Texture.cpp -o Texture.o $(LIBS)

Sprite.o : Sprite.cpp Texture.o Quad.o Model.o
	$(CC) -c Sprite.cpp -o Sprite.o $(LIBS)
 
clean :
	rm main InitGlew.o InitAntix.o ShaderManager.o Model.o Triangle.o ModelsManager.o SceneManager.o Quad.o Sprite.o Texture.o Antix.o libAntix.a 