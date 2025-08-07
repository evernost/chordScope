// ============================================================================
// Project        : chordScope
// Module name    : Main
// File name      : Main.cpp
// File type      : C++ 17
// Purpose        : 
// Author         : QuBi (nitrogenium@outlook.fr)
// Creation date  : August 6th, 2025
// ----------------------------------------------------------------------------
// Best viewed with space indentation (2 spaces)
// ============================================================================

// ============================================================================
// EXTERNALS
// ============================================================================
#include "MainComponent.hpp"



// ----------------------------------------------------------------------------
// CLASS CONSTRUCTOR
// ----------------------------------------------------------------------------
class ChordScope : public juce::JUCEApplication
{
  public:
    const juce::String getApplicationName() override { return "chordScope"; }
    const juce::String getApplicationVersion() override { return "0.1"; }

    void initialise(const juce::String&) override
    {
      mainWindow.reset(new MainWindow("chordScope app - v0.1", new MainComponent(), *this));
    }

    void shutdown() override
    { 
      mainWindow = nullptr;
    }

  private:
    class MainWindow : public juce::DocumentWindow
    {
      public:
        MainWindow(const juce::String& name, juce::Component* c, JUCEApplication& app) : DocumentWindow(
          name, 
          juce::Colours::lightgrey, 
          DocumentWindow::closeButton | DocumentWindow::minimiseButton), owner(app)
        {
          setUsingNativeTitleBar(true);
          setContentOwned(c, true);
          setResizable(false, false); 
          centreWithSize(getWidth(), getHeight());
          setVisible(true);
        }

        void closeButtonPressed() override
        { 
          owner.systemRequestedQuit();
        }

    private:
      JUCEApplication& owner;
    };

  std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(ChordScope)
