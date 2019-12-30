//	OpenGL glossary

typedef int gl_enum;
typedef unsigned gl_ptr;
typedef char* string;
typedef void* gl_null;
//	Shader Programs{
	gl_ptr glCreateShader(gl_enum shaderType);
	/*
		- shaderType:
			GL_VERTEX_SHADER
			GL_FRAGMENTS_SHADER
		
		-> VertexShader
	*/

	gl_ptr glCreateProgram();
	/*
		-> shaderProgram
	*/

	void glShaderSource(gl_ptr vertexShader, unsigned nbrString, string vertexShaderSource[], gl_null NULL);
	/*
		- NbrString:			The number of strings the "vertexShaderSource" have to be read.
		- vertexShaderSource:	the glsl code to compile.
	*/

	void glAttachShader(gl_ptr shaderProgram, gl_ptr vertexShader);
	void glLinkProgram(gl_ptr shaderProgram);

	void glGetShaderiv(gl_ptr vertexShader, gl_enum operationType, int* success);
	/*
		- operationType:
			GL_COMPILE_STATUS
			GL_LINK_STATUS
		
		- success: The pointer to the int which will be set to 0 in case of operation failure
	*/

	void glDeleteShader(gl_ptr vertexShader);
//	}

//	Objects {
	gl_ptr glGenVertexArrays(int size, gl_ptr VAO[]);
    gl_ptr glGenBuffers(gl_ptr size, gl_ptr VBO[]);
    
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    void glBindVertexArray(gl_ptr VAO);

    void glBindBuffer(gl_enum bufferType, gl_ptr VBO);
	void glBufferData(gl_enum bufferType, unsigned size, float[] data, gl_enum drawMethod);
	/*
		- bufferType:
			GL_ARRAY_BUFFER
		-drawMethod:
			- GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
			- GL_DYNAMIC_DRAW: the data is likely to change a lot.
			- GL_STREAM_DRAW: the data will change every time it is drawn.
	*/

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
//	}