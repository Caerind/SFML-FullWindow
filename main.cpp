#include "Window.hpp"

int main()
{
	ke::Window window;

	// 1 - Window properties

	// Create the window
	window.create(sf::VideoMode(1280, 720), "Test", sf::Style::Default);

	// Set the main view
	window.setMainView(sf::View(sf::FloatRect(0.f, 0.f, 1280.f, 720.f)));
	


	// 2 - Loading Window resources

	// Set a font from file, you could have pass a sf::Font*
	window.setDebugInfoFont("assets/font.ttf");
	window.setConsoleFont("assets/font.ttf");

	// Set the icon, you could have pass a sf::Image
	window.setIcon("assets/icon.png");

	// Set the background as scaled, you could have pass a sf::Texture*
	window.useBackgroundScaled("assets/background.png");

	// Set the cursor as custom (sprite)
	window.useCustomMouseCursor("assets/cursor.png");



	// 3 - Debug Info

	// Set a debug info, FPS are displayed by default
	window.setDebugInfo("WindowTitle", window.getTitle());


	// 4 - Console

	// Write on the console 
	window.addConsoleLine("Hello world");

	// Set a simple console command
	window.setConsoleCommand("ping", // The name
		[&window](const ke::Window::CommandArgs& args) // The function
		{
			window.addConsoleLine("pong");
		},
		"Play ping-pong", // Help : The help command is already integrated and will display this optional string
		"Usage : ping"); // Man : The man command is already integrated and will display this optinal string

	// Set a console command using arguments
	window.setConsoleCommand("test", [&window](const ke::Window::CommandArgs& args)
	{
		// Command schema : test newitle -sp path -div value
		if (args.argsCount() >= 1)
		{
			window.setTitle(args[0]);

			if (args.hasOption("sp") && args["sp"].size() >= 1)
			{
				window.setScreenshotPath(args["sp"][0]);
			}

			if (args.hasOption("div") && args["div"].size() >= 1)
			{
				window.setDebugInfo("Value", args["div"][0]);
			}
		}
	});



	// 5 - Callback

	// Set a callback when the window is resized
	window.setResizeCallback([&window](const sf::Vector2u& size)
	{
		window.addConsoleLine("New window size : " + std::to_string(size.x) + "," + std::to_string(size.y));
	});



	// 6 - Action

	// Set action keys
	window.setAction(ke::Window::Action::Console, sf::Keyboard::Quote);
	window.setAction(ke::Window::Action::DebugInfo, sf::Keyboard::Quote);
	window.setAction(ke::Window::Action::Quit, sf::Keyboard::Escape);
	window.setAction(ke::Window::Action::Screenshot, sf::Keyboard::F1);
	window.setAction(ke::Window::Action::Fullscreen, sf::Keyboard::F2);



	// 7 - Main loop

	while (window.isOpen())
	{
		sf::Event event;
		while (window.handleEvent(event))
		{
			// Closed is already handled
			// Action are handled if you have set non-unknown keys
			// Callback may be triggered

			if (event.type == sf::Event::MouseButtonPressed
				|| event.type == sf::Event::TouchBegan)
			{
				sf::Vector2f p = window.getPointerPosition();

				// Do something with the pointer position (Mouse on Desktop, Touch on Mobile)
			}
		}

		window.clear(); // Background is rendered
		window.display(); // DebugInfo are rendered, Console is rendered, Cursor is rendered
	}

	return 0;
}