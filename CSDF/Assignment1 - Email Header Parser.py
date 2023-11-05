import json
import datetime
import pytz


def extract_header(file_name: str) -> dict:
    with open(file_name, 'r') as f:
        spam_header = f.read()

    spam_header_text = spam_header.replace("\t", "").split('\n')
    final_text = []
    last_colon = 0
    for text in spam_header_text:
        if text.find(': ') != -1:
            final_text.append(text)
            last_colon = len(final_text) - 1
        else:
            final_text[last_colon] += text

    spam_header_text = [x.split(": ") for x in final_text]
    spam_header_json = {x[0]: x[1] for x in spam_header_text}
    return spam_header_json


def dump_in_json(content: dict, filename: str) -> None:
    json.dump(content, open(filename, 'w'), indent=4)


def time_required_to_deliver_mail(header_dict: dict) -> datetime.timedelta:
    sent_datetime = header_dict['Received'].split(";")[-1].replace("\n", "").replace("  ", "").split("(")[0].strip()
    received_datetime = header_dict['X-Received'].split(";")[-1].replace("\n", "").replace("  ", "").split("(")[0].strip()

    strp_format = "%a, %d %b %Y %H:%M:%S %z"
    sent_datetime = datetime.datetime.strptime(sent_datetime, strp_format).astimezone(pytz.utc)
    received_datetime = datetime.datetime.strptime(received_datetime, strp_format).astimezone(pytz.utc)
    time_required = received_datetime - sent_datetime
    return time_required


if __name__ == '__main__':
    data = extract_header('spam_header2.txt')
    dump_in_json(data, 'spam_header2.json')
    print(time_required_to_deliver_mail(data))
