#include "window.h"

#include <glm\gtx\transform.hpp>

namespace thirdsengine {
	namespace graphics {

		Window *Window::instance = NULL;

		Window::Window(const char *title, int width, int height) :
			m_Shader(NULL) {
			instance = this;

			m_Title = title;
			m_Width = width;
			m_Height = height;
			m_Closed = false;
			if (!init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
				m_Keys[i] = false;
			for (int i = 0; i < MAX_BUTTONS; i++)
				m_Buttons[i] = false;
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {

			if (!glfwInit()) {
				std::cout << "GLFW could not initialise!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);

			if (glewInit() != GLEW_OK) {
				std::cout << "GLEW could not initialise!" << std::endl;
				return false;
			}

			std::cout << "Using OpenGL " << glGetString(GL_VERSION) << std::endl;

			glfwSetWindowSizeCallback(	m_Window, callbackResize);
			glfwSetKeyCallback(			m_Window, callbackKey);
			glfwSetMouseButtonCallback(	m_Window, callbackMouseButton);
			glfwSetCursorPosCallback(	m_Window, callbackMouseMove);
			glfwSwapInterval(0);  // Disables VSync

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {

			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL error code " << error << std::endl;

			glfwPollEvents();

			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);

			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) != 0;
		}

		void Window::setSize(int width, int height) {
			m_Width = width;
			m_Height = height;
			glm::mat4 proj = glm::perspective(glm::radians(60.0f), getAspect(), 0.1f, 100.0f);
			m_Shader->setUniformMat4("projMatrix", proj);
		}

		void Window::setShader(Shader* shader) {
			m_Shader = shader;
			glm::mat4 proj = glm::perspective(glm::radians(60.0f), getAspect(), 0.1f, 100.0f);
			m_Shader->setUniformMat4("projMatrix", proj);
		}

		void Window::callbackResize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
			instance->setSize(width, height);
		}

		void Window::callbackKey(GLFWwindow *window, int key, int scancode, int action, int mods) {
			instance->m_Keys[key] = (action != GLFW_RELEASE);
		}

		void Window::callbackMouseButton(GLFWwindow *window, int button, int action, int mods) {
			instance->m_Buttons[button] = (action != GLFW_RELEASE);
		}

		void Window::callbackMouseMove(GLFWwindow *window, double xpos, double ypos) {
			instance->m_MouseX = xpos;
			instance->m_MouseY = ypos;
		}

		bool Window::keyPressed(unsigned int keycode) const {
			if (keycode >= MAX_KEYS) return false;
			return m_Keys[keycode];
		}

		bool Window::mouseButtonPressed(unsigned int button) const {
			if (button >= MAX_BUTTONS) return false;
			return m_Buttons[button];
		}

		double Window::mouseX() const {
			return m_MouseX;
		}

		double Window::mouseY() const {
			return m_MouseY;
		}
	}
}