#include "window.h"

namespace thirdsengine {
	namespace graphics {

		Window::Window(const char *title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;
			m_Closed = false;
			if (!init())
			{
				glfwTerminate();
			}
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

			glfwSetWindowSizeCallback(m_Window, callbackResize);

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {

			glfwPollEvents();

			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);

			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) != 0;
		}

		void callbackResize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}