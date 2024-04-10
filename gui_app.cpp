#include <gtk/gtk.h>

class GUI {
    public:
        GUI() {
            // Initialize GTK
            gtk_init(NULL, NULL);
            // Create the main window
            window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
            gtk_window_set_title(GTK_WINDOW(window), "GUI Connect");
            g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
            // Create a label
            label = gtk_label_new("Init 0");
            // Create a button
            button1 = gtk_button_new_with_label("Click Me");
            g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), this);
            // Create a button2
            button2 = gtk_button_new_with_label("Connect");
            g_signal_connect(button2, "clicked", G_CALLBACK(on_button_connect), this);
            // Create a vertical box layout
            vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
            gtk_container_add(GTK_CONTAINER(window), vbox);
            gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
            // Show all widgets
            gtk_widget_show_all(window);
        }

        void run() {
            gtk_main();
        }

    private:
        GtkWidget *window;
        GtkWidget *button1;
        GtkWidget *button2;
        GtkWidget *label;
        GtkWidget *vbox;
        int click_count = 0;

        static void on_button_clicked(GtkWidget *widget, gpointer data) {
            GUI *gui = static_cast<GUI*>(data);
            gui->click_count++;
            gchar *count_str = g_strdup_printf("Click Count1: %d", gui->click_count);
            gtk_label_set_text(GTK_LABEL(gui->label), count_str);
            g_free(count_str);
        }
        static void on_button_connect(GtkWidget *widget, gpointer data) {
            GUI *gui = static_cast<GUI*>(data);
            gui->click_count++;
            gchar *count_str = g_strdup_printf("Click Count2: %d", gui->click_count);
            gtk_label_set_text(GTK_LABEL(gui->label), count_str);
            g_free(count_str);
        }
};

int main(int argc, char *argv[]) {
    GUI gui;
    gui.run();

    return 0;
}