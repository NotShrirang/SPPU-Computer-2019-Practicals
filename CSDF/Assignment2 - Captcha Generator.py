import random
from captcha.image import ImageCaptcha
import streamlit as st


def verify_captcha(user_input, captcha_text):
    if user_input == captcha_text:
        st.success("CAPTCHA Verification Successful!")
        st.balloons()

    else:
        st.error("CAPTCHA Verification Failed!")


title = "CAPTCHA Verification"

st.title(title)

if title == "CAPTCHA Verification":
    btn = st.button("Generate CAPTCHA", key='generate')

if btn:
    image = ImageCaptcha(width=280, height=90)
    captcha_text = str(random.randint(1000, 9999))
    data = image.generate(captcha_text)
    image.write(captcha_text, 'CAPTCHA.png')
    st.image('CAPTCHA.png')
    user_input = st.text_input("Enter the CAPTCHA")
    btn2 = st.button("Verify CAPTCHA", key='verify', help="Click this button to verify the CAPTCHA", on_click=verify_captcha, args=(user_input, captcha_text))