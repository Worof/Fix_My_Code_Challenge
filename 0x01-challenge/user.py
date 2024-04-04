#!/usr/bin/python3
""" 
User class
"""

class User:
    """A class representing a user."""

    def __init__(self):
        """Initialize the user with an email attribute."""
        self.__email = None

    @property
    def email(self):
        """Get the email of the user."""
        return self.__email

    @email.setter
    def email(self, value):
        """Set the email of the user, ensuring it is a string."""
        if not isinstance(value, str):
            raise TypeError("email must be a string")
        self.__email = value
   
    
if __name__ == "__main__":

    u = User()
    u.email = "john@snow.com"
    print(u.email)
