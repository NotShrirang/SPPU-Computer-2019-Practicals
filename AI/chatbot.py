import streamlit as st
import json
import random
import datetime

class ChatBot:
    def __init__(self, database:str) -> None:
        with open("./songQueue.json", 'r') as f:
            songQueueData = dict(json.load(f))
        self.songQueueData = songQueueData
        self.isPlayingSong = self.songQueueData['isPlayingSong']
        self.songQueue = self.songQueueData['queue']
        with open(database, "r") as f:
            self.database = dict(json.load(f))
    
    def _fetch_response(self, input_text: str):
        if input_text in list(self.database.keys()):
            return self.database[input_text]
        input_words_list = input_text.lower().split(" ")
        for word in input_words_list:
            for key, value in self.database.items():
                key_words_list = str(key).split(" ")
                if word in key_words_list:
                    return value
                for key_word in key_words_list:
                    if key_word.find(word) != -1:
                        did_you_mean_text = " ".join(input_words_list)
                        did_you_mean_text = did_you_mean_text.replace(word, key_word)
                        return f'Did you mean "{did_you_mean_text}" ?'
        return "Sorry, I am not able to understand. Could you give me more context please?"
                    
    def response(self, input_text: str):
        input_text = input_text.lower()
        input_text = input_text.replace("?", "")
        input_text = input_text.replace("!", "")
        input_text = input_text.replace(".", "")
        input_text = input_text.replace(",", "")
        input_text = input_text.replace("'", "")
        input_text = input_text.replace('"', "")
        if input_text.startswith("/"):
            input_words_list = input_text.split(" ")
            if len(input_words_list) != 1:
                song_name = input_words_list[1:]
                song_name = ' '.join(song_name).capitalize()
                self.isPlayingSong = True
                self.songQueue.append(song_name)
                with open('./songQueue.json', 'w') as f:
                    json.dump({"queue": self.songQueue, "isPlayingSong": self.isPlayingSong}, f)
                return f"Playing {song_name}..."
            elif input_words_list[0] == "/stop":
                if self.isPlayingSong:
                    self.isPlayingSong = False
                    self.songQueue = []
                    with open('./songQueue.json', 'w') as f:
                        json.dump({"queue": self.songQueue, "isPlayingSong": self.isPlayingSong}, f)
                    return "Stopped music..."
                else:
                    return "Music is not playing..."
            elif input_words_list[0] == "/pause":
                if self.isPlayingSong:
                    self.isPlayingSong = False
                    with open('./songQueue.json', 'w') as f:
                        json.dump({"queue": self.songQueue, "isPlayingSong": self.isPlayingSong}, f)
                    return "Paused music..."
                else:
                    return "Music is not playing..."
            elif input_words_list[0] == "/resume":
                if self.isPlayingSong:
                    self.isPlayingSong = True
                    with open('./songQueue.json', 'w') as f:
                        json.dump({"queue": self.songQueue, "isPlayingSong": self.isPlayingSong}, f)
                    return "Resumed music..."
                else:
                    return "Music is already playing..."
            elif input_words_list[0] == "/skip":
                if self.isPlayingSong:
                    self.songQueue.pop(0)
                    with open('./songQueue.json', 'w') as f:
                        json.dump({"queue": self.songQueue, "isPlayingSong": self.isPlayingSong}, f)
                    return "Playing next track..."
                else:
                    return "Music is not playing..."
            elif input_words_list[0] == "/queue":
                return "\n".join(list(map(lambda song: f"{self.songQueue.index(song)+1} : {song}", self.songQueue)))
            else:
                return f"Invalid command '{input_words_list[0]}'"
        elif input_text.find("date")!= -1:
            return datetime.datetime.now().strftime("%d/%m/%Y")
        elif input_text.find("time")!= -1:
            return datetime.datetime.now().strftime("%H:%M:%S")
        elif input_text.find("weather")!= -1:
            return "It's sunny today!"
        elif input_text.find("dice") != -1:
            return random.randint(1, 6)
        else:
            response = self._fetch_response(str(input_text))
            return response
                

st.title("GreenBot")
chatbot = ChatBot("./chatbotData.json")

input_text = st.text_input(label="", placeholder="Whisper something ...")
st.caption("Commands: /play <song name>, /stop, /pause, /skip, /queue")
if input_text:
    response = chatbot.response(input_text)
    st.header(response)
st.subheader("Song Queue")
st.table(chatbot.songQueue)