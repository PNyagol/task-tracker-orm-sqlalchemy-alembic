import click
from database import SessionLocal, init_db
from models import Task

@click.group()
def cli():
    """Task Tracker CLI"""
    init_db()

@cli.command()
@click.argument('title')
def add(title):
    """Add a new task"""

    db = SessionLocal()
    task = Task(title=title)
    db.add(task)
    db.commit()
    db.close()
    click.echo(f"✅ Added task: {title}")

@cli.command()
def list():
    """List all tasks"""

    db = SessionLocal()
    tasks = db.query(Task).all()
    for task in tasks:
        status = "✔️" if task.done else "❌"
        click.echo(f"[{task.id}] {task.title} - {status}")
    db.close()

@cli.command()
@click.argument('task_id', type=int)
def done(task_id):
    """Mark task as done"""
    db = SessionLocal()
    task = db.query(Task).get(task_id)
    if task:
        task.done = True
        db.commit()
        click.echo(f"✅ Task {task_id} marked as done")
    else:
        click.echo("❌ Task not found")
    db.close()

@cli.command()
@click.argument('task_id', type=int)
def delete(task_id):
    """Delete a task"""
    db = SessionLocal()
    task = db.query(Task).get(task_id)
    if task:
        db.delete(task)
        db.commit()
        click.echo(f"🗑️ Deleted task {task_id}")
    else:
        click.echo("❌ Task not found")
    db.close()

if __name__ == "__main__":
    cli()
