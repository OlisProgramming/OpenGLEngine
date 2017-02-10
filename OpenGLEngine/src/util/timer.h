#pragma once

#include <Windows.h>
#include <deque>

#define TIMER_FRAMES_IN_MEMORY 60

namespace thirdsengine {

	class Timer {
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
		std::deque<double> m_Previous;

	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}

		void reset() {
			QueryPerformanceCounter(&m_Start);
		}

		double tick() {
			LARGE_INTEGER end;
			QueryPerformanceCounter(&end);
			unsigned __int64 cycles = end.QuadPart - m_Start.QuadPart;
			double ms = cycles*m_Frequency;
			m_Previous.push_back(ms);
			if (m_Previous.size() > TIMER_FRAMES_IN_MEMORY)
				m_Previous.pop_front();
			reset();
			return ms;
		}

		double getFPS() {
			return 1.0 / m_Previous.back();
		}

		double getFPSStable() {
			double total = 0.0;
			for (double d : m_Previous)
				total += d;
			return m_Previous.size() / total;
		}
	};
}