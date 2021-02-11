from flask import Flask, render_template,g, request, session, redirect, url_for, abort
import hashlib
import sqlite3

class User:
    def __init__(self, id, username, password):
        self.id=id
        self.username=username
        self.password=password

    def __repr__(self):
        return f'<User: {self.username}>'

users = []
users.append(User(id=1,username="pippo",password="nonteladico"))

app = Flask(__name__)
app.secret_key = "parolabella"

@app.route("/") #http://127.0.0.1:5000/
def index():
    return render_template("login.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session.pop('user_id', None)
        username = request.form["username"]
        password = hashlib.sha512(request.form["password"].encode()).hexdigest()

        completion = validate(username, password)  # check if user exist and the password is correct

        if completion:
            session['user_id'] = user.id
            return redirect(url_for("home"))  # redirect user to the secret page
        else:
            error = "Invalid Credentials. Please try again."  # stay in the login page and say wrong credentials

        return render_template("login.html", error=error)

    return render_template("login.html")

@app.before_request
def before_request():
    g.user = None

    if "user_id" in session:
        user = [x for x in users if x.id == session["user_id"]][0]
        g.user = user

def validate(username,password):
    with sqlite3.connect("static/credential.db") as conn:   #connect to DB
        cursor = conn.cursor()  #create a cursor

        #search for user email
        cursor.execute(f"SELECT email FROM users WHERE email = '{username}' AND password = '{password}' ")
        corrispondance = cursor.fetchall()

    return len(corrispondance) # 1 --> user found!  |  0 --> user not found!

@app.route("/home") #http://127.0.0.1:5000/pagina2/
def home():
    if not g.user:
        return redirect(url_for('login'))
    return render_template("home.html")

if __name__ =="__main__":
    app.run(host="127.0.0.1", debug="on")
