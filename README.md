# SFML-FullWindow

A fully featured Window class for SFML

Features :
- Creation process : easier and support Android
- Easily manage fullscreen
- Add a lot of getters about the data of the Window
- Improve Icon loading
- Add MainView : which is the default view of the Window, used to be easily compatible from Windows & Android
- Get the position of mouse and touch relatively from the window
- Use getPointerPosition() to get the position of mouse on Windows or the position of the touch on Android
- Custom Mouse Cursor (using sprite)
- Take a screenshot easily
- Easily set a background : color, scaled sprite or repeated sprite
- Console (you can create your owns commands)
- Debug-Info (you can display your owns infos)
- FPS tool
- Callback with std::function : Resize, GainedFocus, LostFocus, Close, ErrorLog, WarningLog, InfoLog
- Action with key customisable : Console, Screenshot, DebugInfo, Quit, Fullscreen
- Replace pollEvent/waitEvent by handleEvent, which use pollEvent but use waitEvent on Android when the app isn't focused
- Hide unused functions from the user