Game::Game(): Title("zero"), Width(800),Height(600),window(nullptr),renderer(nullptr){}
Game::Game(const std::string& title, float width, float height)
: Title(title), Width(width), Height(height),  
      window(nullptr), renderer(nullptr) {}
Game::~Game(){}
