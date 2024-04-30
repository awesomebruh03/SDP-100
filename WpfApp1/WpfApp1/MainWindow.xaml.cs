using System.Windows;

namespace YourNamespace
{
    public partial class LoginWindow : Window
    {
        public LoginWindow()
        {
            InitializeComponent();
        }

        private void Login_Click(object sender, RoutedEventArgs e)
        {
            string username = txtUsername.Text;
            string password = txtPassword.Password;

            // Here, you would typically perform your login logic, such as verifying credentials.
            // For simplicity, let's just display a message box.
            MessageBox.Show($"Username: {username}\nPassword: {password}");
        }
    }
}
