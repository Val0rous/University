package it.unibo.apice.oop.p20patterns.observer.auladone;

public class App {

    public static void main(String[] args) {
        final FieldGUI gui = new FieldGUIImpl();
        gui.addObserver(new WriteToConsole());
        gui.addObserver(new QuitOnExit());
    }

}
