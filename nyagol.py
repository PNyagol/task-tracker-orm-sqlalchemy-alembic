import click

@click.command()
@click.argument("first")
@click.argument("last")
def greet(first, last):
    """Say hello to someone."""
    click.echo(f"Hello, {first} {last}!")

if __name__ == "__main__":
    greet()
