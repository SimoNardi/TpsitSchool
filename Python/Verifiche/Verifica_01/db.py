import sqlite3
import os.path
from pprint import pprint as pp

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DB_PATH = os.path.join(BASE_DIR, "data", "operations.db")

class Db():

    def __init__(self, path=DB_PATH):
        self.connection = sqlite3.connect(path)

    def close(self):
        self.connection.close()

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()

    def NumbOfOper(self):
        cursor = self.connection.cursor()
        cursor.execute("""
            SELECT seq
            FROM sqlite_sequence
        """)
        return [p[0] for p in cursor.fetchall()]

    def operation(self):
        cursor = self.connection.cursor()
        cursor.execute("""
            SELECT operation
            FROM operations
        """)
        return [p[0] for p in cursor.fetchall()]

    def client(self):
        cursor = self.connection.cursor()
        cursor.execute("""
                    SELECT client
                    FROM operations
                """)
        return [p[0] for p in cursor.fetchall()]
