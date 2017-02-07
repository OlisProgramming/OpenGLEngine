#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace thirdsengine {
	namespace graphics {

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

		class Window
		{
		public:
			static Window *instance;

		private:
			int m_Width, m_Height;
			const char *m_Title;
			GLFWwindow *m_Window;
			bool m_Closed;

			bool m_Keys[MAX_KEYS];
			bool m_Buttons[MAX_BUTTONS];
			double m_MouseX, m_MouseY;

		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			bool keyPressed(unsigned int keycode) const;
			bool mouseButtonPressed(unsigned int button) const;
			double mouseX() const;
			double mouseY() const;

		private:
			bool init();
			static void callbackResize(GLFWwindow *window, int width, int height);
			static void callbackKey(GLFWwindow *window, int key, int scancode, int action, int mods);
			static void callbackMouseButton(GLFWwindow *window, int button, int action, int mods);
			static void callbackMouseMove(GLFWwindow *window, double xpos, double ypos);
		};
	}
}