#include "MainComponent.hpp"

class SineApp : public juce::JUCEApplication
{
public:
  const juce::String getApplicationName() override { return "SineWave MIDI Drawer"; }
  const juce::String getApplicationVersion() override { return "1.0"; }

  void initialise(const juce::String&) override
  {
    mainWindow.reset(new MainWindow("SineWave MIDI Drawer", new MainComponent(), *this));
  }

  void shutdown() override { mainWindow = nullptr; }

private:
  class MainWindow : public juce::DocumentWindow
  {
  public:
      MainWindow(const juce::String& name, juce::Component* c, JUCEApplication& app)
          : DocumentWindow(name, juce::Colours::lightgrey, DocumentWindow::allButtons), owner(app)
      {
          setUsingNativeTitleBar(true);
          setContentOwned(c, true);
          centreWithSize(getWidth(), getHeight());
          setVisible(true);
      }

      void closeButtonPressed() override { owner.systemRequestedQuit(); }

  private:
    JUCEApplication& owner;
  };

  std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(SineApp)
