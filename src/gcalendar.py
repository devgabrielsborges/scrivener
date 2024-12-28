from google.oauth2.credentials import Credentials
from google_auth_oautthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
from googleepicclient.discovery import build

import os
import datetime


SCOPES = ["https://www.googleapis.com/auth/calendar"]


def authenticate_google_calendar():
    creds = None

    if os.path.exists("token.json"):
        creds = Credentials.from_authorized_user_file("token.json")

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file("../credentials.json", SCOPES)
            creds = flow.run_local_server(port=0)

        with open("token.json", "w") as token:
            token.write(creds.to_json())

    return build("calendar", "v3", credentials=creds)


def list_tasks():
    service = authenticate_google_calendar()
    now = datetime.datetime.utcnow().isoformat() + "Z"
    events_result = (
        service.events()
        .list(
            calendarId="primary",
            timeMin=now,
            maxResults=10,
            singleEvents=True,
            orderBy="startTime",
        )
        .execute()
    )
    events = events_result.get("items", [])

    if not events:
        print("No upcoming events found.")
    for event in events:
        start = event["start"].get("dateTime", event["start"].get("date"))
        print(start, event["summary"])


def add_task(summary: str, start_date: str, end_date: str, location: str = "America/New_York"):
    authenticate_google_calendar()
    event = {
            "summary": summary,
            "start": {"dateTime": start_date, "timeZone": location},
            "end": {"dateTime": end_date, "timeZone": location},
            }
    service = authenticate_google_calendar()
    event = service.events().insert(calendarId="primary", body=event).execute()
    print("Event created: %s" % (event.get("htmlLink")))


def delete_task(summary: str):
    service = authenticate_google_calendar()
    event_id = get_task_id(summary)
    if event_id:
        service.events().delete(calendarId="primary", eventId=event_id).execute()
        print("Event deleted")
    else:
        print("Event not found")


def get_task_id(summary: str):
    service = authenticate_google_calendar()
    now = datetime.datetime.utcnow().isoformat() + "Z"
    events_result = (
        service.events()
        .list(
            calendarId="primary",
            timeMin=now,
            maxResults=10,
            singleEvents=True,
            orderBy="startTime",
        )
        .execute()
    )
    events = events_result.get("items", [])

    if not events:
        print("No upcoming events found.")
    for event in events:
        if event["summary"] == summary:
            return event["id"]
    return None


authenticate_google_calendar()
